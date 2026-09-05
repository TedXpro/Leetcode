# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity: $O(L)$
*   **Step 1**: The `for` loop advances the `fast` pointer $n$ steps: $O(n)$.
*   **Step 2**: The `while` loop advances both `slow` and `fast` pointers until `fast` reaches the end: $O(L - n)$, where $L$ is the length of the list.
*   **Total**: $O(n + (L - n)) = O(L)$. We traverse the list exactly once.

### Space Complexity: $O(1)$
*   **Auxiliary Memory**: The algorithm uses a constant amount of extra space for two pointers (`slow`, `fast`) and one `dummy` node, regardless of the input size.
*   **Return Space**: The space used for the modified linked list is not counted as auxiliary space.

### Algorithmic Invariant: Two Pointers (Sliding Window)
The core technique is the **Two-Pointer "Gap" strategy**. By maintaining a fixed distance of $n$ nodes between the `fast` and `slow` pointers, the algorithm ensures that when `fast` reaches the end (`None`), the `slow` pointer is positioned exactly at the node *preceding* the target node to be removed.

### Edge Cases Handled
*   **Removing the Head**: By using a `dummy` node pointing to `head`, the logic correctly handles cases where the node to be removed is the first node (the `slow` pointer stops at the `dummy` node).
*   **List with One Node**: If the list has one node and $n=1$, `fast` becomes `None` after the first loop, the `while` loop is skipped, and `dummy.next` is correctly updated to `None`.
*   **Removing the Last Node**: The logic correctly identifies the node before the tail and updates its `next` pointer to `None`.

### Optimization / Alternatives
*   **Micro-optimizations**: The current implementation is optimal in terms of Big-O. No further reduction in time or space complexity is possible for a singly linked list.
*   **Alternative (Two-Pass)**: One could calculate the length of the list first ($L$), then traverse again to the $(L-n)^{th}$ node. This is also $O(L)$ but requires two full passes instead of one.
*   **Alternative (Recursion)**: One could use a recursive approach to traverse to the end and remove the node during the "unwinding" phase. This is elegant but incurs $O(L)$ space complexity due to the call stack.
