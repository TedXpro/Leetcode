import os
import re
import json
import time
import requests

LEETCODE_SESSION = os.environ.get("LEETCODE_SESSION")
LEETCODE_CSRF_TOKEN = os.environ.get("LEETCODE_CSRF_TOKEN")
GEMINI_API_KEY = os.environ.get("GEMINI_API_KEY")
SOLUTIONS_DIR = "solutions"

LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"
HEADERS = {
    "content-type": "application/json",
    "origin": "https://leetcode.com",
    "referer": "https://leetcode.com/submissions/",
    "cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}; csrftoken={LEETCODE_CSRF_TOKEN};",
    "x-csrftoken": LEETCODE_CSRF_TOKEN or "",
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)"
}

LANG_EXTENSIONS = {
    "python": "py", "python3": "py", "cpp": "cpp", "c": "c",
    "java": "java", "javascript": "js", "typescript": "ts",
    "golang": "go", "rust": "rs", "csharp": "cs", "ruby": "rb"
}

def query_leetcode(query: str, variables: dict):
    res = requests.post(LEETCODE_GRAPHQL_URL, json={"query": query, "variables": variables}, headers=HEADERS)
    res.raise_for_status()
    return res.json()

def get_recent_accepted_submissions():
    query = """
    query submissionList($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        submissions {
          id
          titleSlug
          statusDisplay
          lang
          timestamp
        }
      }
    }
    """
    data = query_leetcode(query, {"offset": 0, "limit": 20})
    submissions = data.get("data", {}).get("submissionList", {}).get("submissions", [])
    return [s for s in submissions if s.get("statusDisplay") == "Accepted"]

def get_submission_code(submission_id: str):
    query = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        question {
          questionFrontendId
          title
          titleSlug
          difficulty
          content
          topicTags { name }
        }
      }
    }
    """
    data = query_leetcode(query, {"submissionId": int(submission_id)})
    return data.get("data", {}).get("submissionDetails", {})

def generate_ai_analysis(problem_title: str, difficulty: str, lang: str, code: str) -> str:
    """Uses Gemini 1.5/2.0 Flash to evaluate time and space complexity."""
    if not GEMINI_API_KEY:
        return "AI Analysis skipped: `GEMINI_API_KEY` not configured."

    url = f"https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key={GEMINI_API_KEY}"
    prompt = f"""
    Analyze the following accepted LeetCode solution for the problem "{problem_title}" ({difficulty}):
    Language: {lang}

    ```
    {code}
    ```

    Provide a concise, highly structured technical analysis in Markdown format:
    1. **Time Complexity**: Formal Big-O with clear asymptotic step breakdown.
    2. **Space Complexity**: Formal Big-O separating auxiliary stack/data structures vs output space.
    3. **Algorithmic Invariant / Core Pattern**: (e.g., Two Pointers, Monotonic Stack, DP recurrence).
    4. **Critical Edge Cases Handled**: What boundary scenarios does this logic satisfy?
    5. **Optimization / Refactoring Opportunities**: Is there a more optimal time/space or idiomatic approach?
    """
    
    payload = {"contents": [{"parts": [{"text": prompt}]}]}
    try:
        res = requests.post(url, json=payload, headers={"Content-Type": "application/json"}, timeout=30)
        res.raise_for_status()
        candidates = res.json().get("candidates", [])
        return candidates[0]["content"]["parts"][0]["text"]
    except Exception as e:
        return f"Failed to generate analysis: {str(e)}"

def main():
    os.makedirs(SOLUTIONS_DIR, exist_ok=True)
    accepted = get_recent_accepted_submissions()
    synced_any = False

    for sub in accepted:
        slug = sub["titleSlug"]
        sub_id = sub["id"]

        details = get_submission_code(sub_id)
        if not details:
            continue

        q_info = details.get("question", {})
        frontend_id = q_info.get("questionFrontendId", "0").zfill(4)
        folder_name = f"{frontend_id}-{slug}"
        target_dir = os.path.join(SOLUTIONS_DIR, folder_name)

        # Skip if problem has already been synced
        if os.path.exists(target_dir):
            continue

        print(f"Syncing & analyzing: {folder_name}...")
        os.makedirs(target_dir, exist_ok=True)

        # 1. Save Solution Code
        ext = LANG_EXTENSIONS.get(sub["lang"], "txt")
        with open(os.path.join(target_dir, f"solution.{ext}"), "w", encoding="utf-8") as f:
            f.write(details.get("code", ""))

        # 2. Save Problem README.md
        tags = ", ".join([t["name"] for t in q_info.get("topicTags", [])])
        readme_content = f"# [{q_info.get('title')}] - {q_info.get('difficulty')}\n\n"
        readme_content += f"**Tags:** {tags}\n\n"
        readme_content += f"[LeetCode Problem Link](https://leetcode.com/problems/{slug}/)\n\n"
        readme_content += "---\n\n"
        # Strip HTML tags simply if present
        clean_content = re.sub(r'<[^>]+>', '', q_info.get("content", ""))
        readme_content += clean_content
        with open(os.path.join(target_dir, "README.md"), "w", encoding="utf-8") as f:
            f.write(readme_content)

        # 3. Save AI ANALYSIS.md
        analysis = generate_ai_analysis(
            problem_title=q_info.get("title", slug),
            difficulty=q_info.get("difficulty", "Unknown"),
            lang=sub["lang"],
            code=details.get("code", "")
        )
        with open(os.path.join(target_dir, "ANALYSIS.md"), "w", encoding="utf-8") as f:
            f.write(f"# Complexity & Algorithmic Analysis\n\n{analysis}")

        synced_any = True
        time.sleep(2) # Avoid rate limits

    if synced_any:
        print("New problems synced and analyzed.")
    else:
        print("No new problems to sync.")

if __name__ == "__main__":
    main()
