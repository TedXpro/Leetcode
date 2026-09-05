import os
import re
import html
import sys
from typing import List, Dict, Tuple

if sys.stdout.encoding and sys.stdout.encoding.lower() != 'utf-8':
    try:
        sys.stdout.reconfigure(encoding='utf-8')
        sys.stderr.reconfigure(encoding='utf-8')
    except Exception:
        pass

LANG_MAP = {
    ".cpp": "C++",
    ".py": "Python",
    ".java": "Java",
    ".js": "JavaScript",
    ".ts": "TypeScript",
    ".go": "Go",
    ".rs": "Rust",
    ".cs": "C#",
    ".c": "C",
    ".rb": "Ruby",
    ".swift": "Swift",
    ".kt": "Kotlin"
}

def make_progress_bar(count: int, total: int, width: int = 25) -> str:
    if total == 0:
        return "░" * width
    filled = int(round((count / total) * width))
    filled = max(0, min(width, filled))
    return "█" * filled + "░" * (width - filled)

def parse_problem_dir(dir_path: str) -> dict:
    folder_name = os.path.basename(dir_path)
    m = re.match(r'^(\d{4})-(.*)$', folder_name)
    if not m:
        return {}

    num = m.group(1)
    slug = m.group(2)
    title = slug.replace('-', ' ').title()
    difficulty = "Medium"
    tags = []
    
    readme_path = os.path.join(dir_path, "README.md")
    if os.path.exists(readme_path):
        try:
            with open(readme_path, "r", encoding="utf-8", errors="ignore") as f:
                c = f.read()

                # 1. HTML Title format: <h2><a href="...">6. Zigzag Conversion</a></h2>
                m_html_title = re.search(r'<h2><a[^>]*>(?:\d+\.\s*)?(.*?)</a></h2>', c)
                # 2. Markdown Title format: # [Title] - Difficulty
                m_md_title = re.search(r'#\s*\[(.*?)\]', c)

                if m_html_title:
                    title = html.unescape(m_html_title.group(1).strip())
                elif m_md_title:
                    title = html.unescape(m_md_title.group(1).strip())

                # Difficulty detection
                m_html_diff = re.search(r'<h3>(Easy|Medium|Hard)</h3>', c, re.IGNORECASE)
                m_md_diff = re.search(r'-\s*(Easy|Medium|Hard)\b', c, re.IGNORECASE)

                if m_html_diff:
                    difficulty = m_html_diff.group(1).capitalize()
                elif m_md_diff:
                    difficulty = m_md_diff.group(1).capitalize()
                elif "Hard" in c[:350]:
                    difficulty = "Hard"
                elif "Easy" in c[:350]:
                    difficulty = "Easy"
                elif "Medium" in c[:350]:
                    difficulty = "Medium"

                m_tags = re.search(r'\*\*Tags:\*\*\s*(.*?)\n', c)
                if m_tags:
                    tags = [t.strip() for t in m_tags.group(1).split(",") if t.strip()]
        except Exception:
            pass

    # Find solutions
    solution_links = []
    has_analysis = os.path.exists(os.path.join(dir_path, "ANALYSIS.md"))
    norm_dir = dir_path.replace("\\", "/")
    if not norm_dir.startswith("./"):
        norm_dir = f"./{norm_dir}"

    for fname in sorted(os.listdir(dir_path)):
        _, ext = os.path.splitext(fname)
        if ext in LANG_MAP:
            lang_label = LANG_MAP[ext]
            rel_link = f"{norm_dir}/{fname}"
            solution_links.append((lang_label, rel_link))

    return {
        "dir": norm_dir,
        "num": num,
        "slug": slug,
        "title": title,
        "difficulty": difficulty,
        "tags": tags,
        "solutions": solution_links,
        "has_analysis": has_analysis
    }

def generate_readme():
    search_base = "solutions" if os.path.exists("solutions") else "."
    raw_dirs = [
        d for d in os.listdir(search_base)
        if re.match(r'^\d{4}-', d) and os.path.isdir(os.path.join(search_base, d))
    ]
    raw_dirs.sort()

    problems = []
    for d in raw_dirs:
        full_path = os.path.join(search_base, d) if search_base != "." else d
        info = parse_problem_dir(full_path)
        if info:
            problems.append(info)

    total_problems = len(problems)
    diff_counts = {"Easy": 0, "Medium": 0, "Hard": 0}
    lang_counts: Dict[str, int] = {}
    analysis_count = 0

    for p in problems:
        diff_counts[p["difficulty"]] = diff_counts.get(p["difficulty"], 0) + 1
        if p["has_analysis"]:
            analysis_count += 1
        for lang_label, _ in p["solutions"]:
            lang_counts[lang_label] = lang_counts.get(lang_label, 0) + 1

    easy_c = diff_counts.get("Easy", 0)
    med_c = diff_counts.get("Medium", 0)
    hard_c = diff_counts.get("Hard", 0)

    easy_pct = f"{(easy_c / total_problems * 100):.1f}" if total_problems else "0"
    med_pct = f"{(med_c / total_problems * 100):.1f}" if total_problems else "0"
    hard_pct = f"{(hard_c / total_problems * 100):.1f}" if total_problems else "0"

    easy_bar = make_progress_bar(easy_c, total_problems, 25)
    med_bar = make_progress_bar(med_c, total_problems, 25)
    hard_bar = make_progress_bar(hard_c, total_problems, 25)

    # Markdown Generation
    readme = [
        "<div align=\"center\">\n",
        "  <h1>⚡ LeetCode Solutions & Algorithmic Portfolio</h1>",
        "  <p><b>Automated Ingestion, Asymptotic Complexity Review, and Real-Time Statistical Index</b></p>\n",
        f"  <p>",
        f"    <img src=\"https://img.shields.io/badge/Solved-{total_problems}_Problems-orange?style=for-the-badge&logo=leetcode&logoColor=white\" alt=\"Total Solved\" />",
        f"    <img src=\"https://img.shields.io/badge/Easy-{easy_c}-00b8a3?style=for-the-badge\" alt=\"Easy\" />",
        f"    <img src=\"https://img.shields.io/badge/Medium-{med_c}-ffc01e?style=for-the-badge\" alt=\"Medium\" />",
        f"    <img src=\"https://img.shields.io/badge/Hard-{hard_c}-ff375f?style=for-the-badge\" alt=\"Hard\" />",
        f"    <img src=\"https://img.shields.io/badge/Gemini_AI-Powered_Analysis-4285F4?style=for-the-badge&logo=google&logoColor=white\" alt=\"Gemini AI\" />",
        f"  </p>\n",
        "</div>\n",
        "---\n",
        "## 📌 Overview\n",
        "This repository maintains a comprehensive catalog of solved LeetCode challenges. Each solution is synchronized through automated GitHub Actions workflows and evaluated with formal Big-O asymptotic analysis, algorithmic invariants, and boundary edge cases powered by the **Google Gemini AI Model Carousel** (`gemini-3.1-flash-lite`, `gemini-3.8-flash`, etc.).\n",
        "## 📊 Metrics & Problem Breakdown\n",
        "### 🎯 Difficulty Distribution\n",
        "| Difficulty | Solved | Percentage | Visual Ratio |",
        "| :--- | :---: | :---: | :--- |",
        f"| 🟢 **Easy** | **{easy_c}** | {easy_pct}% | `{easy_bar}` |",
        f"| 🟡 **Medium** | **{med_c}** | {med_pct}% | `{med_bar}` |",
        f"| 🔴 **Hard** | **{hard_c}** | {hard_pct}% | `{hard_bar}` |",
        f"| 🏆 **Total** | **{total_problems}** | **100%** | **{total_problems} Accepted Solutions** |\n",
        "### 💻 Languages Distribution\n",
        "| Language | Solutions Count | Share | Progress Bar |",
        "| :--- | :---: | :---: | :--- |"
    ]

    total_lang_solutions = sum(lang_counts.values()) or 1
    for lang, count in sorted(lang_counts.items(), key=lambda x: x[1], reverse=True):
        share_pct = f"{(count / total_lang_solutions * 100):.1f}%"
        bar = make_progress_bar(count, total_lang_solutions, 20)
        readme.append(f"| **{lang}** | {count} | {share_pct} | `{bar}` |")

    readme.extend([
        "\n---\n",
        "## 🔄 Automated Ingestion & Review Workflow\n",
        "```mermaid",
        "flowchart LR",
        "    subgraph LC[\"🌐 LeetCode\"]",
        "        A[\"Accepted Submissions\"]",
        "    end",
        "",
        "    subgraph GHA[\"⚙️ GitHub Actions Workflow\"]",
        "        B[\"sync_leetcode.py<br/>(Ingestion)\"]",
        "        C[\"Gemini Model Carousel<br/>(3.1-Lite → 3.5-Lite → 3.8-Flash ...)\"]",
        "        D[\"update_readme.py<br/>(Dynamic Stats & Index)\"]",
        "        E[\"Automated PR (base: main)<br/>with Detailed AI Review\"]",
        "    end",
        "",
        "    subgraph Repo[\"📁 Repository\"]",
        "        F[\"Solution Code & Problem README\"]",
        "        G[\"ANALYSIS.md<br/>(Time/Space & Invariants)\"]",
        "        H[\"Root README.md<br/>(Live Stats & Table)\"]",
        "    end",
        "",
        "    A --> B",
        "    B --> C",
        "    C --> F & G",
        "    B --> D",
        "    D --> H",
        "    F & G & H --> E",
        "```\n",
        "---\n",
        "## 📚 Solutions Catalog\n",
        f"> Total Indexed Problems: **{total_problems}** | Problems with AI Invariant Analysis: **{analysis_count}**\n",
        "| # | Problem Title | Difficulty | Solutions | AI Complexity Analysis |",
        "| :---: | :--- | :---: | :---: | :---: |"
    ])

    diff_emojis = {
        "Easy": "🟢 Easy",
        "Medium": "🟡 Medium",
        "Hard": "🔴 Hard"
    }

    for p in problems:
        num = p["num"]
        slug = p["slug"]
        title = p["title"]
        diff_str = diff_emojis.get(p["difficulty"], p["difficulty"])
        
        problem_link = f"[{title}](https://leetcode.com/problems/{slug}/)"
        
        if p["solutions"]:
            sol_links_str = " ".join([f"[`{label}`]({url})" for label, url in p["solutions"]])
        else:
            sol_links_str = f"[`Code`]({p['dir']}/)"

        analysis_str = f"[`🧠 ANALYSIS.md`]({p['dir']}/ANALYSIS.md)" if p["has_analysis"] else "`-`"
        
        readme.append(f"| {num} | {problem_link} | {diff_str} | {sol_links_str} | {analysis_str} |")

    readme.append(
        "\n---\n"
        "<div align=\"center\">\n"
        "  <sub>Synchronized automatically with Google Gemini AI and GitHub Actions.</sub>\n"
        "</div>\n"
    )

    content = "\n".join(readme)
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(content)

    print(f"Updated README.md with {total_problems} problems ({easy_c} Easy, {med_c} Medium, {hard_c} Hard).")

if __name__ == "__main__":
    generate_readme()
