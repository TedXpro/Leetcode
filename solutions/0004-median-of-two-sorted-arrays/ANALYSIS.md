# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**$O(\log(\min(m, n)))$**
*   **Breakdown**: The algorithm performs a binary search on the smaller array (length $m$). In each iteration, the search space `[low, high]` is halved. The operations inside the loop (index lookups and comparisons) are $O(1)$. Since we ensure `nums1` is the smaller array via the initial swap, the complexity is logarithmic relative to the smaller input size.

### Space Complexity
**$O(1)$**
*   **Breakdown**: The algorithm uses a constant amount of auxiliary space for variables (`m`, `n`, `tot`, `low`, `high`, `start`, `end`, and boundary values). No additional data structures are created; the return value is a single float.

### Algorithmic Invariant
**Binary Search on Partitioning**
*   The core technique is to find a partition point in both arrays such that the left half contains exactly half (or half + 1) of the total elements, and every element in the left half is less than or equal to every element in the right half. This satisfies the condition: `max(left_part) <= min(right_part)`.

### Edge Cases Handled
*   **Empty Arrays**: Handled by the `float('-inf')` and `float('inf')` assignments, which allow the partition to exist even if one array is entirely to the left or right of the median.
*   **Disjoint Arrays**: The `nums1L <= nums2R` and `nums2L <= nums1R` checks correctly identify valid partitions even when one array's values are entirely smaller than the other's.
*   **Odd vs. Even Total Length**: The `(m + n + 1) // 2` calculation ensures the left partition is correctly sized for both parity cases, and the final conditional logic handles the median calculation accordingly.
*   **Single Element Arrays**: The `start > 0` and `start < m` checks prevent `IndexError` when the partition falls at the very beginning or end of the arrays.

### Optimization / Alternatives
*   **Micro-optimizations**: The current implementation is already optimal for this problem. One could potentially remove the `float()` casting if the environment guarantees integer inputs, but it is safer as written.
*   **Alternative Approaches**:
    *   **K-th Smallest Element**: The problem can be solved by finding the $k$-th smallest element in the union of two sorted arrays using a recursive approach (reducing $k$ by $k/2$ each step). This also achieves $O(\log(m+n))$ time but is often more complex to implement correctly than the binary search partition method.
    *   **Merge and Sort**: A naive $O(m+n)$ approach (merging the arrays) is simpler but fails the "Hard" constraint requirements for efficiency.
