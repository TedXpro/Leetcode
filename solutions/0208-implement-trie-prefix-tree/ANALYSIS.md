# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
*   **`insert(word)`**: $O(m)$, where $m$ is the length of the word. We iterate through each character once, performing constant-time dictionary lookups and insertions.
*   **`search(word)`**: $O(m)$, where $m$ is the length of the word. We traverse the tree depth-wise; each step is $O(1)$.
*   **`startsWith(prefix)`**: $O(p)$, where $p$ is the length of the prefix. Similar to search, we traverse the tree up to the length of the prefix.

### Space Complexity
*   **Auxiliary Space**: $O(N \cdot \Sigma)$, where $N$ is the total number of characters across all inserted words and $\Sigma$ is the alphabet size (size of the dictionary). 
*   **Worst Case**: In the worst case (no common prefixes), every character requires a new `TrieNode`. Each node stores a dictionary of children, leading to $O(N)$ nodes, each potentially holding references to its children.

### Algorithmic Invariant
*   **Tree Traversal / Prefix Hashing**: The core technique is a **N-ary Tree** structure where each node represents a character state. The invariant is that a path from the root to any node represents a unique prefix, and the `_end` boolean flag marks the termination of a valid word.

### Edge Cases Handled
*   **Empty String**: The logic handles empty strings implicitly (the loop won't execute, returning the root's `_end` status or `True` for `startsWith`).
*   **Prefixes of Existing Words**: `startsWith` correctly returns `True` even if the prefix is not a complete word.
*   **Words as Prefixes of Others**: The `_end` flag distinguishes between a complete word and a path that is merely a prefix of a longer word.
*   **Non-existent Paths**: The `if char not in curr._children` check safely handles lookups for characters that were never inserted.

### Optimization / Alternatives
*   **Fixed-size Array**: If the alphabet is restricted (e.g., only lowercase English letters 'a'-'z'), replacing the dictionary `_children` with an array of size 26 (`[None] * 26`) can improve performance by reducing hash map overhead and memory fragmentation.
*   **Memory Efficiency**: If memory is constrained, a **Ternary Search Tree** could be used to reduce the number of null pointers, though this increases time complexity to $O(m \log \Sigma)$.
*   **Compressed Trie (Radix Tree)**: If the Trie contains many long, non-branching paths, nodes can be merged to store strings instead of single characters, significantly reducing the number of nodes.
