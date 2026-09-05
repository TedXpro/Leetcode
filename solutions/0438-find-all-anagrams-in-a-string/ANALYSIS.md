# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**$O(N)$**, where $N$ is the length of string `s`.
1.  **Initialization**: Counting characters in `p` and the first window of `s` takes $O(M)$, where $M$ is the length of `p`.
2.  **Sliding Window**: The `while` loop runs $N - M + 1$ times. Inside the loop, comparing two lists of size 26 is $O(1)$ (constant time), and updating the counts is $O(1)$.
3.  **Total**: $O(M + (N - M)) = O(N)$.

### Space Complexity
**$O(1)$** (Auxiliary) / **$O(K)$** (Return).
*   **Auxiliary**: The two frequency arrays (`substring_count`, `p_count`) are fixed at size 26, regardless of input size, resulting in $O(1)$ extra space.
*   **Return**: The `answer` list can store up to $O(N)$ indices in the worst case (e.g., `s = "aaaaa"`, `p = "aa"`).

### Algorithmic Invariant
**Sliding Window with Frequency Map Comparison.**
The algorithm maintains a fixed-size window of length `len(p)`. It preserves the invariant that `substring_count` always represents the character frequencies of the current window `s[left:right+1]`. By comparing this against the target `p_count`, it identifies anagrams without re-scanning the entire substring.

### Edge Cases Handled
*   **`len(s) < len(p)`**: Explicitly handled at the start; returns an empty list immediately.
*   **Empty strings**: Implicitly handled (though constraints usually define $1 \le s, p \le 3 \times 10^4$).
*   **No anagrams found**: The `answer` list remains empty, and the loop completes correctly.
*   **Identical strings**: Correctly identifies the index `0` if `s == p`.

### Optimization / Alternatives
*   **Micro-optimization**: Instead of comparing two lists of size 26 (which is $O(26)$), maintain a `matches` variable that tracks how many character counts currently align. This reduces the comparison step to $O(1)$.
*   **Alternative (Hash Map)**: Using `collections.Counter` is more readable but generally slower due to hashing overhead compared to the fixed-size array (which acts as a direct-address table).
*   **Alternative (Rolling Hash)**: One could use Rabin-Karp style rolling hashes to compare substrings in $O(1)$, though this introduces the risk of hash collisions and is generally overkill for this problem.
