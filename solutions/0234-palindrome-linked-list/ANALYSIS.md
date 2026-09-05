# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**$O(n)$**
1.  **Finding the middle:** The `fast` pointer traverses the list at $2x$ speed, reaching the end in $n/2$ steps.
2.  **Reversing the second half:** The `slow` pointer traverses the remaining $n/2$ nodes to reverse their pointers.
3.  **Comparison:** The final `while` loop traverses at most $n/2$ nodes to compare values.
Total: $O(n/2 + n/2 + n/2) = O(n)$.

### Space Complexity
**$O(1)$**
*   **Auxiliary Memory:** The algorithm performs an in-place reversal of the linked list pointers. No additional data structures (like arrays or stacks) are used.
*   **Return Space:** The result is a boolean, which does not scale with input size.

### Algorithmic Invariant
**Two Pointers (Fast/Slow) + In-place Linked List Reversal.**
The algorithm uses the "Tortoise and Hare" approach to identify the midpoint, reverses the second half of the list to allow for bidirectional comparison, and then validates the palindrome property by traversing from both ends toward the center.

### Edge Cases Handled
*   **Empty List (`head is None`):** The `while fast and fast.next` loop is skipped; the function returns `True` (vacuously a palindrome).
*   **Single Node:** `fast` and `slow` remain at the head; the comparison loop correctly validates the single node.
*   **Even-length Lists:** `fast` becomes `None`, triggering the `prev = None` logic to correctly isolate the two halves.
*   **Odd-length Lists:** `fast` stops at the last node; the `else` block (`slow = slow.next`) skips the exact middle element, which is irrelevant for palindrome verification.

### Optimization / Alternatives
*   **Micro-optimization:** The current implementation modifies the input list structure. If the list must remain intact, a second pass is required to reverse the second half back to its original state, which maintains $O(n)$ time but adds complexity.
*   **Alternative (Stack):** One could push the first half of the list into a stack and compare it with the second half. This is easier to implement but requires **$O(n)$ space**, which is less efficient than the current in-place approach.
*   **Alternative (Recursion):** Using a recursive call stack to reach the end and comparing values on the way back is elegant but incurs **$O(n)$ space** due to the call stack depth.
