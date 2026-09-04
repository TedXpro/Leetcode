import os
import re
import json
import time
import requests
import sys
from typing import List, Dict, Tuple, Optional

if sys.stdout.encoding and sys.stdout.encoding.lower() != 'utf-8':
    try:
        sys.stdout.reconfigure(encoding='utf-8')
        sys.stderr.reconfigure(encoding='utf-8')
    except Exception:
        pass

LEETCODE_SESSION = os.environ.get("LEETCODE_SESSION")
LEETCODE_CSRF_TOKEN = os.environ.get("LEETCODE_CSRF_TOKEN")
GEMINI_API_KEY = os.environ.get("GEMINI_API_KEY")
SOLUTIONS_DIR = "."
PR_BODY_FILE = "PR_BODY.md"

LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"
HEADERS = {
    "content-type": "application/json",
    "origin": "https://leetcode.com",
    "referer": "https://leetcode.com/submissions/",
    "cookie": f"LEETCODE_SESSION={LEETCODE_SESSION or ''}; csrftoken={LEETCODE_CSRF_TOKEN or ''};",
    "x-csrftoken": LEETCODE_CSRF_TOKEN or "",
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)"
}

LANG_EXTENSIONS = {
    "python": "py", "python3": "py", "cpp": "cpp", "c": "c",
    "java": "java", "javascript": "js", "typescript": "ts",
    "golang": "go", "rust": "rs", "csharp": "cs", "ruby": "rb",
    "swift": "swift", "kotlin": "kt", "scala": "scala", "php": "php"
}

# Carousel using active Gemini 3 family models with fallback hierarchy
MODEL_CAROUSEL = [
    "gemini-3.8-flash",
    "gemini-3.5-flash-lite",
    "gemini-3.7-flash",
    "gemini-3.1-flash-lite",
    "gemini-3.6-flash",
    "gemini-3.5-flash",
    "gemini-3-flash-preview"
]

def query_leetcode(query: str, variables: dict) -> dict:
    res = requests.post(LEETCODE_GRAPHQL_URL, json={"query": query, "variables": variables}, headers=HEADERS, timeout=20)
    res.raise_for_status()
    return res.json()

def get_recent_accepted_submissions(limit: int = 20) -> list:
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

def get_submission_code(submission_id: str) -> dict:
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

def generate_ai_analysis(problem_title: str, difficulty: str, lang: str, code: str) -> Tuple[str, str]:
    """
    Evaluates algorithmic complexity with the Gemini model carousel.
    Fails fast per model (10s timeout, no retry delay) and cascades instantly to the next model.
    Returns a tuple of (analysis_markdown, model_used).
    """
    if not GEMINI_API_KEY:
        return "AI Analysis skipped: `GEMINI_API_KEY` not configured.", "None"

    headers = {
        "Content-Type": "application/json",
        "x-goog-api-key": GEMINI_API_KEY
    }

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
    
    payload = {
        "contents": [{"parts": [{"text": prompt}]}],
        "generationConfig": {
            "temperature": 0.2,
            "maxOutputTokens": 1024
        }
    }

    for model in MODEL_CAROUSEL:
        url = f"https://generativelanguage.googleapis.com/v1beta/models/{model}:generateContent"
        try:
            # Fast 10s timeout, no retry loops: if model is busy or times out, immediately cascade
            res = requests.post(url, json=payload, headers=headers, timeout=10)
            
            if res.status_code == 200:
                data = res.json()
                candidates = data.get("candidates", [])
                if candidates:
                    parts = candidates[0].get("content", {}).get("parts", [])
                    if parts and "text" in parts[0]:
                        return parts[0]["text"].strip(), model

            if res.status_code in (429, 503):
                reason = "Rate limit (429)" if res.status_code == 429 else "High demand (503)"
                print(f"[{model}] {reason}. Skipping to next model...", file=sys.stderr)
                continue

            # Log other status codes briefly
            try:
                err_msg = res.json().get('error', {}).get('message', res.text)
            except Exception:
                err_msg = res.text
            print(f"[{model}] HTTP {res.status_code}: {err_msg[:120]}. Skipping...", file=sys.stderr)

        except requests.exceptions.Timeout:
            print(f"[{model}] timeout (>10s). Skipping to next model...", file=sys.stderr)
        except requests.exceptions.RequestException as err:
            print(f"[{model}] network error ({type(err).__name__}). Skipping...", file=sys.stderr)
        except Exception as err:
            print(f"[{model}] error ({type(err).__name__}). Skipping...", file=sys.stderr)

    fallback_msg = (
        "*Algorithmic analysis temporarily unavailable due to upstream API service demand. "
        "Will be refreshed on subsequent sync cycles.*"
    )
    return fallback_msg, "Unavailable"

def update_analysis_file(analysis_path: str, lang: str, new_analysis: str, model_used: str = ""):
    """
    Updates or appends a specific language section inside ANALYSIS.md safely
    without regex string substitution bugs.
    """
    section_header = f"## {lang.capitalize()} Analysis"
    meta_tag = f"> *Reviewed with `{model_used}`*\n\n" if model_used and model_used != "Unavailable" else ""
    new_section_body = f"{meta_tag}{new_analysis.strip()}"

    doc_header = "# Complexity & Algorithmic Analysis\n\n"
    sections: Dict[str, str] = {}

    if os.path.exists(analysis_path):
        with open(analysis_path, "r", encoding="utf-8") as f:
            content = f.read()

        # Split existing markdown into sections by '## ' headers
        raw_parts = re.split(r'(?m)^(?=## )', content)
        for part in raw_parts:
            part = part.strip()
            if not part:
                continue
            if part.startswith("# "):
                lines = part.split("\n", 1)
                doc_header = lines[0].strip() + "\n\n"
            elif part.startswith("## "):
                lines = part.split("\n", 1)
                h_name = lines[0].strip()
                body = lines[1].strip() if len(lines) > 1 else ""
                sections[h_name] = body

    sections[section_header] = new_section_body

    # Reconstruct document cleanly
    output = [doc_header.rstrip()]
    for h_name, body in sections.items():
        output.append(f"\n\n{h_name}\n\n{body}")

    with open(analysis_path, "w", encoding="utf-8") as f:
        f.write("\n".join(output).strip() + "\n")

def extract_metric(analysis_text: str, key: str) -> str:
    """Extracts a short metric snippet like Time Complexity or Invariant from the analysis text."""
    pattern = rf"-?\s*\*\*{re.escape(key)}\*\*:\s*(.*?)(?=\n-|\n\n|\Z)"
    match = re.search(pattern, analysis_text, re.IGNORECASE | re.DOTALL)
    if match:
        first_line = match.group(1).strip().split("\n")[0]
        return first_line[:80].strip()
    return "-"

def write_pr_body(synced_items: List[dict], output_path: str = PR_BODY_FILE):
    """Generates an informative, structured Pull Request body."""
    if not synced_items:
        with open(output_path, "w", encoding="utf-8") as f:
            f.write("No new accepted submissions were detected in this sync cycle.\n")
        return

    content = [
        "## 🚀 LeetCode Daily Sync & Algorithmic Complexity Review\n",
        f"Pulled **{len(synced_items)}** newly accepted solution(s) from LeetCode with automated algorithmic complexity breakdown.\n",
        "### 📊 Synced Submissions Summary\n",
        "| Problem | Difficulty | Language | Invariant / Pattern | Time Complexity | Space Complexity | AI Reviewer |",
        "| :--- | :---: | :---: | :--- | :--- | :--- | :--- |"
    ]

    for item in synced_items:
        title_link = f"[{item['title']}](https://leetcode.com/problems/{item['slug']}/)"
        diff_badge = f"**{item['difficulty']}**"
        time_c = extract_metric(item['analysis'], "Time Complexity")
        space_c = extract_metric(item['analysis'], "Space Complexity")
        pattern_c = extract_metric(item['analysis'], "Algorithmic Invariant")
        model_badge = f"`{item['model']}`" if item['model'] != "Unavailable" else "*Offline*"
        
        content.append(
            f"| {item['id']} - {title_link} | {diff_badge} | `{item['lang']}` | {pattern_c} | {time_c} | {space_c} | {model_badge} |"
        )

    content.append("\n### 🔍 Detailed Algorithmic & Complexity Breakdown\n")

    for item in synced_items:
        content.append(
            f"<details>\n"
            f"<summary><b>{item['id']} - {item['title']} ({item['lang']})</b> [Reviewer: <code>{item['model']}</code>]</summary>\n\n"
            f"{item['analysis']}\n\n"
            f"- **Repository Path:** [`{item['folder']}`](./{item['folder']}/)\n"
            f"- **Problem Statement:** [`README.md`](./{item['folder']}/README.md)\n"
            f"- **Detailed Analysis:** [`ANALYSIS.md`](./{item['folder']}/ANALYSIS.md)\n"
            f"</details>\n"
        )

    content.append(
        "---\n"
        "*Automated synchronization powered by GitHub Actions and Google Gemini Carousel.*"
    )

    with open(output_path, "w", encoding="utf-8") as f:
        f.write("\n".join(content) + "\n")

def main():
    accepted = get_recent_accepted_submissions(limit=20)
    synced_items = []

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

        primary_file = os.path.join(target_dir, f"{folder_name}.{ext}")
        alt_file = os.path.join(target_dir, f"solution.{ext}")
        solution_file = alt_file if os.path.exists(alt_file) and not os.path.exists(primary_file) else primary_file

        new_code = details.get("code", "").strip()

        # Check if identical code is already stored
        if os.path.exists(solution_file):
            with open(solution_file, "r", encoding="utf-8", errors="ignore") as f:
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
        analysis, model_used = generate_ai_analysis(
            problem_title=q_info.get("title", slug),
            difficulty=q_info.get("difficulty", "Unknown"),
            lang=lang,
            code=new_code
        )
        update_analysis_file(os.path.join(target_dir, "ANALYSIS.md"), lang, analysis, model_used)

        synced_items.append({
            "id": frontend_id,
            "title": q_info.get("title", slug),
            "slug": slug,
            "difficulty": q_info.get("difficulty", "Unknown"),
            "lang": lang,
            "folder": folder_name,
            "model": model_used,
            "analysis": analysis
        })

        time.sleep(1)

    # Write PR Summary
    write_pr_body(synced_items)

    if synced_items:
        print(f"Successfully synced and analyzed {len(synced_items)} submission(s).")
    else:
        print("No new submission changes detected.")

if __name__ == "__main__":
    main()
