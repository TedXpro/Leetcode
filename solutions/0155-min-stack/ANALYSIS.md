# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**O(1)** for all operations:
*   **`push`**: Constant time `min()` comparison and `append` operation.
*   **`pop`**: Constant time `list.pop()` operation.
*   **`top`**: Constant time indexing of the last element.
*   **`getMin`**: Constant time indexing of the precomputed minimum stored in the tuple.

### Space Complexity
**O(n)**:
*   **Auxiliary Memory**: The solution stores a tuple `(value, min_val)` for every element pushed onto the stack. This results in linear space growth relative to the number of elements ($n$).
*   **Return Space**: N/A (no additional data structures are returned).

### Algorithmic Invariant
**State Augmentation**: The solution maintains the "Min" property by augmenting each stack element with the current minimum at that specific depth. By storing the minimum alongside the value, the stack effectively becomes a **prefix-minimum tracking structure**, ensuring the minimum is always available at the top of the stack without needing to re-scan.

### Edge Cases Handled
*   **Empty Stack**: The `if not self.stack` check in `push` correctly initializes the first element as its own minimum.
*   **Duplicate Values**: The `min()` function correctly handles duplicate values (e.g., pushing `2` then `2` results in both having a `min_val` of `2`).
*   **Descending/Ascending Sequences**: The logic correctly updates the `min_val` regardless of whether the incoming value is smaller, larger, or equal to the previous minimum.

### Optimization / Alternatives
*   **Space Optimization (Two-Stack Approach)**: Instead of storing a tuple for every element, use a secondary "min stack" that only pushes a value when it is less than or equal to the current minimum. This saves space when there are many redundant values, though it remains O(n) in the worst case.
*   **Micro-optimization**: In Python, using a single list of tuples is generally efficient, but if memory is extremely constrained, using two separate lists (one for values, one for mins) can sometimes reduce object overhead, though it complicates the `pop` logic.
*   **Alternative**: A `collections.deque` could be used for slightly faster `pop` operations in some specific environments, though `list` is already amortized O(1) for `append`/`pop`.
