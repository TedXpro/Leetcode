# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
*   **`addWord(word)`**: $O(m)$, where $m$ is the length of the word. We iterate through each character once to traverse/create nodes in the Trie.
*   **`search(word)`**: 
    *   **Best/Average Case**: $O(m)$ for standard words.
    *   **Worst Case**: $O(n \cdot 26^m)$ in the presence of many `.` wildcards, where $n$ is the number of words in the dictionary and $m$ is the length of the search string. In the worst case (e.g., `.....`), the algorithm must explore all branches of the Trie at every level.

### Space Complexity
*   **Auxiliary Space**: $O(N \cdot M)$, where $N$ is the total number of words added and $M$ is the average length of the words. This accounts for the Trie nodes stored in memory.
*   **Recursion Stack**: $O(m)$ for the `dfs` call stack, where $m$ is the length of the search word.

### Algorithmic Invariant
*   **Trie + Backtracking (DFS)**: The structure uses a **Prefix Tree (Trie)** to store words. The search operation employs **Backtracking** to handle the `.` wildcard, effectively branching the search into all possible child nodes whenever a wildcard is encountered.

### Edge Cases Handled
*   **Empty String**: `addWord("")` sets `_end = True` at the root; `search("")` correctly returns `True` if an empty string was added.
*   **Wildcard at Start/End**: The `dfs` logic handles `.` at any index, including the first and last positions.
*   **Non-existent Paths**: If a character is not in `_children` and is not a `.`, the `search` function returns `False` immediately.
*   **Partial Matches**: The `node._end` boolean ensures that a prefix (e.g., searching "app" when only "apple" is stored) returns `False`.

### Optimization / Alternatives
*   **Length-based Bucketing**: Store words in a dictionary where keys are word lengths (`self.words = collections.defaultdict(list)`). For `search`, only iterate through words of the exact length. This avoids Trie traversal for words that cannot possibly match.
*   **Regex Pre-compilation**: If the search pattern is complex, Python's `re` module could be used, though it would require storing all words in a single list, making `addWord` $O(1)$ and `search` $O(N \cdot M)$.
*   **Trie Node Optimization**: Replace the `_children` dictionary with a fixed-size array `[None] * 26` if the character set is strictly lowercase English letters to reduce hash map overhead and memory fragmentation.
