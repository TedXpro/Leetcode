# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**$O(n)$**
*   **Iteration:** The algorithm performs a single pass over the input string of length $n$.
*   **Operations:** Each character involves dictionary lookups, stack pushes, and stack pops, all of which are $O(1)$ amortized operations.

### Space Complexity
**$O(n)$**
*   **Auxiliary Memory:** In the worst-case scenario (e.g., a string of all opening brackets like `((((((`), the stack will store all $n$ characters.
*   **Return Space:** The dictionary `pairs` is constant size ($O(1)$) as it only stores three fixed mappings regardless of input size.

### Algorithmic Invariant
**Stack-based Matching (LIFO)**
*   The algorithm maintains a **Last-In, First-Out (LIFO)** structure to ensure that the most recently opened bracket is the first one to be closed. It enforces the nested structure of valid parentheses by verifying that the top of the stack matches the corresponding opening bracket for every closing bracket encountered.

### Edge Cases Handled
*   **Empty String:** Returns `True` (as `not stack` evaluates to `True`).
*   **Starting with Closing Bracket:** The `if not stack` check immediately returns `False`.
*   **Unbalanced/Trailing Openers:** The final `return not stack` ensures that any remaining opening brackets result in `False`.
*   **Mismatched Types:** The `stack[-1] != pairs[ch]` check ensures that `(]` or `[}` are correctly identified as invalid.

### Optimization / Alternatives
*   **Micro-optimization:** For very large strings, using a pre-allocated list or a `collections.deque` can slightly improve performance, though standard Python lists are highly optimized for stack operations.
*   **Alternative (Recursion):** One could use recursion to validate, but this would lead to $O(n)$ space complexity on the call stack and is generally less efficient due to function call overhead.
*   **Alternative (String Replacement):** Repeatedly calling `s.replace("()", "").replace("[]", "").replace("{}", "")` is a common "naive" approach, but it results in **$O(n^2)$** time complexity due to string immutability and repeated scanning, making it significantly slower than the stack approach.
