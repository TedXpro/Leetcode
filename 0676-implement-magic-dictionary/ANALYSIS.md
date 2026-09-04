# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
*   **`buildDict`**: $O(N \cdot L)$, where $N$ is the number of words and $L$ is the average length of a word. We iterate through every character of every word to populate the Trie.
*   **`search`**: $O(26^L)$ in the worst case (a dense Trie), but effectively $O(L \cdot 26)$ per search. Because we only allow one modification, the branching factor is limited: at each step, we explore all children. If the current character matches, we continue; if it doesn't, we can branch once to a different character if `modified` is `False`.

### Space Complexity
*   **Auxiliary Space**: $O(N \cdot L \cdot \Sigma)$, where $\Sigma$ is the alphabet size (26). This represents the storage of the Trie nodes.
*   **Recursion Stack**: $O(L)$ due to the depth of the DFS matching the length of the `searchWord`.

### Algorithmic Invariant
*   **Trie-based Backtracking (DFS)**: The algorithm uses a Trie to store the dictionary and a state-tracking DFS to explore paths. The invariant is the `modified` boolean flag, which ensures that exactly one character substitution occurs to satisfy the "magic" condition.

### Edge Cases Handled
*   **Exact Match vs. Magic Match**: The `modified` flag ensures that a word identical to one in the dictionary returns `False` (as the problem requires exactly one character change).
*   **Word Length Mismatch**: The base case `idx == len(searchWord)` ensures that only words of the exact same length as the `searchWord` are considered valid.
*   **Empty Dictionary**: The Trie remains empty, and `search` correctly returns `False` as the root has no children.

### Optimization / Alternatives
*   **Pre-computation (Hashing)**: Instead of a Trie, store all words in a hash map where keys are "generalized" versions of the words (e.g., replacing each character with a wildcard `*`). For `searchWord`, generate all possible variations with one character replaced by `*` and check if any exist in the map. This reduces search time to $O(L^2)$ but increases `buildDict` time to $O(N \cdot L^2)$.
*   **Trie Pruning**: In the `search` function, if `modified` is already `True`, we don't need to iterate through all children; we can simply perform a direct lookup (`node._children.get(target_char)`), which would significantly speed up the second half of the search.
