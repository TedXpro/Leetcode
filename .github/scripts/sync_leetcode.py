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

def get_recent_accepted_submissions(limit: int = 20):
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
    data = query_leetcode(query, {"offset": 0, "limit": limit})
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
    if not GEMINI_API_KEY:
        return "AI Analysis skipped: `GEMINI_API_KEY` not configured."

    url = f"https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key={GEMINI_API_KEY}"
    prompt = f"""
    Analyze this accepted LeetCode solution for "{problem_title}" ({difficulty}) in {lang}:

    ```{lang}
    {code}
    ```

    Respond strictly in Markdown with these concise sections:
    - **Time Complexity**: Formal Big-O with step-by-step breakdown.
    - **Space Complexity**: Formal Big-O (auxiliary memory vs return space).
    - **Algorithmic Invariant**: Core technique (Two Pointers, DP, Monotonic Stack, etc.).
    - **Edge Cases Handled**: Key boundaries verified by this logic.
    - **Optimization / Alternatives**: Possible micro-optimizations or alternate algorithmic approaches.
    """
    
    payload = {"contents": [{"parts": [{"text": prompt}]}]}
    try:
        res = requests.post(url, json=payload, headers={"Content-Type": "application/json"}, timeout=30)
        res.raise_for_status()
        candidates = res.json().get("candidates", [])
        return candidates[0]["content"]["parts"][0]["text"]
    except Exception as e:
        return f"Failed to generate analysis: {str(e)}"

def update_analysis_file(analysis_path: str, lang: str, new_analysis: str):
    """Updates or appends a specific language section inside ANALYSIS.md."""
    section_header = f"## {lang.capitalize()} Analysis"
    
    if os.path.exists(analysis_path):
        with open(analysis_path, "r", encoding="utf-8") as f:
            content = f.read()
    else:
        content = "# Complexity & Algorithmic Analysis\n\n"

    # Regex to replace existing section for this language if it exists
    pattern = rf"{re.escape(section_header)}.*?(?=\n## |\Z)"
    new_section = f"{section_header}\n\n{new_analysis.strip()}\n\n"

    if re.search(pattern, content, flags=re.DOTALL):
        content = re.sub(pattern, new_section, content, flags=re.DOTALL)
    else:
        content = content.rstrip() + "\n\n" + new_section

    with open(analysis_path, "w", encoding="utf-8") as f:
        f.write(content)

def main():
    os.makedirs(SOLUTIONS_DIR, exist_ok=True)
    accepted = get_recent_accepted_submissions(limit=20)
    synced_any = False

    for sub in accepted:
        slug = sub["titleSlug"]
        sub_id = sub["id"]
        lang = sub["lang"]
        ext = LANG_EXTENSIONS.get(lang, "txt")

        details = get_submission_code(sub_id)
        if not details:
            continue

        q_info = details.get("question", {})
        frontend_id = q_info.get("questionFrontendId", "0").zfill(4)
        folder_name = f"{frontend_id}-{slug}"
        target_dir = os.path.join(SOLUTIONS_DIR, folder_name)
        os.makedirs(target_dir, exist_ok=True)

        solution_file = os.path.join(target_dir, f"solution.{ext}")
        new_code = details.get("code", "").strip()

        # Check if identical code is already stored
        if os.path.exists(solution_file):
            with open(solution_file, "r", encoding="utf-8") as f:
                existing_code = f.read().strip()
            if existing_code == new_code:
                print(f"Skipping {folder_name} ({lang}): Code unchanged.")
                continue

        print(f"Processing {folder_name} [{lang}]...")

        # 1. Write or Overwrite Solution Code
        with open(solution_file, "w", encoding="utf-8") as f:
            f.write(details.get("code", ""))

        # 2. Write Problem Description (Only if missing)
        readme_file = os.path.join(target_dir, "README.md")
        if not os.path.exists(readme_file):
            tags = ", ".join([t["name"] for t in q_info.get("topicTags", [])])
            clean_content = re.sub(r'<[^>]+>', '', q_info.get("content", ""))
            readme_content = (
                f"# [{q_info.get('title')}] - {q_info.get('difficulty')}\n\n"
                f"**Tags:** {tags}\n\n"
                f"[LeetCode Problem Link](https://leetcode.com/problems/{slug}/)\n\n"
                f"---\n\n{clean_content}\n"
            )
            with open(readme_file, "w", encoding="utf-8") as f:
                f.write(readme_content)

        # 3. Generate & Update Language Analysis
        analysis = generate_ai_analysis(
            problem_title=q_info.get("title", slug),
            difficulty=q_info.get("difficulty", "Unknown"),
            lang=lang,
            code=new_code
        )
        update_analysis_file(os.path.join(target_dir, "ANALYSIS.md"), lang, analysis)

        synced_any = True
        time.sleep(1) # Prevent rate limits

    if synced_any:
        print("Submissions updated successfully.")
    else:
        print("No submission changes detected.")

if __name__ == "__main__":
    main()
