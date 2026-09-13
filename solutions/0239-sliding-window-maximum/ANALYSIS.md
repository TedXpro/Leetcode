# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**$O(n)$**
*   **Breakdown:** Each element in `nums` is pushed into the `deque` exactly once and popped from the `deque` at most once. The `for` loop runs $n$ times, and the inner `while` loop operations are amortized $O(1)$ because every index is added and removed from the deque a constant number of times.

### Space Complexity
**$O(k)$**
*   **Auxiliary Space:** $O(k)$, as the `deque` stores at most $k$ indices at any given time (the size of the sliding window).
*   **Return Space:** $O(n - k + 1)$ to store the result list, which is typically excluded from auxiliary space complexity analysis.

### Algorithmic Invariant
**Monotonic Decreasing Queue**
*   The core technique maintains a deque of indices such that the values corresponding to these indices are in strictly decreasing order. The front of the deque (`deq[0]`) always holds the index of the maximum element for the current window.

### Edge Cases Handled
*   **$k = 1$:** The loop correctly identifies each element as the maximum of its own window.
*   **$k = n$:** The loop processes the entire array and returns the global maximum as the only element.
*   **Strictly Increasing/Decreasing Arrays:** The monotonic property ensures the deque correctly discards obsolete smaller elements or maintains the sequence.
*   **Duplicate Values:** The `nums[deq[-1]] < nums[i]` condition ensures that if a new value is equal to an existing value in the deque, the old index is popped, keeping the deque size minimal and correct.

### Optimization / Alternatives
*   **Micro-optimization:** For Python, using `collections.deque` is already optimal. Accessing `nums[deq[-1]]` is $O(1)$.
*   **Alternative (Heap):** A Max-Heap could store `(value, index)` pairs. This would result in **$O(n \log n)$** time complexity, as heap operations are logarithmic.
*   **Alternative (Segment Tree / Sparse Table):** These structures allow for $O(1)$ or $O(\log n)$ range maximum queries, but they require $O(n \log n)$ or $O(n)$ preprocessing time and higher space overhead, making them less efficient than the monotonic queue for this specific sliding window problem.
