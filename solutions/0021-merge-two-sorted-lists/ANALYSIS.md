# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.5-flash-lite`*

- **Time Complexity**: $O(N + M)$
  - *Breakdown*: The `while` loop iterates through both linked lists node by node until one (or both) are exhausted. In the worst-case scenario, every single node from `list1` (length $N$) and `list2` (length $M$) is visited exactly once. The remaining elements from the unexhausted list are appended in $O(1)$ time. Thus, total time is strictly linear relative to the total number of nodes.

- **Space Complexity**: $O(1)$ auxiliary space
  - *Breakdown*: The algorithm only uses a fixed number of pointers (`dummy`, `curr`) regardless of the input size. It does not allocate new nodes or use recursion (which would consume $O(N + M)$ call-stack space). The return list simply rearranges the pointers of the existing input nodes, requiring zero extra auxiliary memory.

- **Algorithmic Invariant**: Two Pointers / Iterative Merging
  - *Core Technique*: Maintaining a "dummy head" node to simplify edge cases at the start of the result list, alongside a traversal pointer (`curr`) that greedily attaches the smaller of the two current nodes from `list1` and `list2`.

- **Edge Cases Handled**:
  - Both lists are empty (`list1 = None`, `list2 = None`).
  - One list is empty while the other contains elements.
  - Lists of unequal lengths.
  - Lists containing duplicate values.
  - Negative integers and mixed positive/negative values.

- **Optimization / Alternatives**:
  - *Recursive Approach*: Can be implemented recursively, which is more concise and reads functionally, though it incurs $O(N + M)$ auxiliary space on the call stack.
  - *In-place Optimization*: The current iterative approach is already asymptotically optimal in both time and space. No micro-optimizations are necessary since pointer manipulation directly modifies references without redundant checks.
