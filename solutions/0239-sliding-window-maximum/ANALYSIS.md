# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**$O(n)$**
*   **Breakdown:** Each element in `nums` is added to the `deque` exactly once and removed from the `deque` at most once. The `for` loop runs $n$ times, and the inner `while` loop operations are amortized $O(1)$ because each index is pushed and popped at most once throughout the entire execution.

### Space Complexity
**$O(k)$**
*   **Auxiliary Space:** $O(k)$ to store indices in the `deque`, as the window size is limited to $k$.
*   **Return Space:** $O(n - k + 1)$ to store the result array. Excluding the output, the auxiliary space complexity is $O(k)$.

### Algorithmic Invariant
**Monotonic Decreasing Queue:**
The algorithm maintains a `deque` of indices such that the values corresponding to these indices are in strictly decreasing order. The front of the `deque` (`deq[0]`) always points to the index of the maximum element within the current sliding window $[i-k+1, i]$.

### Edge Cases Handled
*   **$k=1$:** The loop correctly identifies the maximum of every single-element window (the element itself).
*   **$k=n$:** The loop processes the entire array and returns a single maximum value.
*   **Strictly Increasing/Decreasing Arrays:** The `while` loop logic ensures that elements that can no longer be the maximum are discarded, handling sorted inputs efficiently.
*   **Duplicate Values:** The condition `nums[deq[-1]] < nums[i]` ensures that if a new value is equal to an existing value in the queue, the old index is popped, keeping the queue size minimal and correct.

### Optimization / Alternatives
*   **Micro-optimization:** In Python, `collections.deque` is already highly optimized. Using a list as a stack is not recommended due to $O(n)$ pop operations from the front.
*   **Alternative (Heap):** A Max-Heap could be used to store `(value, index)` pairs. This would result in **$O(n \log n)$** time complexity. While easier to conceptualize, it is strictly slower than the monotonic queue approach.
*   **Alternative (Segment Tree / Sparse Table):** These could solve the Range Maximum Query (RMQ) problem in $O(n \log n)$ preprocessing and $O(1)$ query time, but they are overkill and less efficient than the $O(n)$ sliding window approach.
