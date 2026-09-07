# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.5-flash-lite`*

- **Time Complexity**: $\mathcal{O}(N)$ where $N$ is the number of elements in `temperatures`. 
  - *Breakdown*: The outer loop iterates through each index from $0$ to $N-1$ exactly once. The inner `while` loop pops elements from the stack. Although there is a nested loop, each index is pushed onto the stack at most once and popped from the stack at most once. Therefore, the total number of stack operations across the entire execution is bounded by $2N$, yielding linear time complexity.

- **Space Complexity**: $\mathcal{O}(N)$ auxiliary memory (plus $\mathcal{O}(N)$ for the return array).
  - *Breakdown*: The `answer` array takes $\mathcal{O}(N)$ space. The monotonic stack stores indices of the `temperatures` array. In the worst-case scenario (e.g., strictly decreasing temperatures), the stack will store all $N$ indices, resulting in $\mathcal{O}(N)$ space complexity.

- **Algorithmic Invariant**: **Monotonic Stack**.
  - *Core Technique*: The stack maintains a strictly decreasing sequence of indices based on their corresponding temperatures. When a warmer temperature is encountered at the current index `i`, it resolves the "next greater element" for all previous indices stored in the stack that have smaller temperatures.

- **Edge Cases Handled**:
  - *Strictly Decreasing Temperatures* (e.g., `[3, 2, 1]`): No elements trigger the `while` loop; indices simply accumulate in the stack, and the function correctly returns `[0, 0, 0]`.
  - *Strictly Increasing Temperatures* (e.g., `[1, 2, 3]`): Each new element immediately pops the previous element, resolving distances as `1`, and correctly returns `[1, 1, 0]`.
  - *Single Element* (e.g., `[70]`): Loops once, stack operations are skipped, and the function correctly returns `[0]`.
  - *Plateaus / Equal Temperatures* (e.g., `[73, 73, 73]`): Handled naturally since the condition `temperatures[i] > temperatures[stack[-1]]` is false for equal values, preventing premature popping and leaving them in the stack until a higher temperature appears (or returning `0` if none exists).

- **Optimization / Alternatives**:
  - *Backward Iteration Approach*: As shown in the commented-out code, you can iterate from right to left using a monotonic decreasing stack to skip checking useless lower temperatures, though asymptotically the time and space complexities remain $\mathcal{O}(N)$.
  - *Space Optimization*: If modifying the input array is permitted (which is rarely the case in LeetCode interviews), the `answer` array could theoretically be avoided, though virtually impossible to achieve $\mathcal{O}(1)$ auxiliary space while tracking future warmer days without losing original data or violating read-only constraints. In Python, localized variable caching (`len()`, stack lookups) can offer marginal micro-optimizations, but the current solution is already optimal.
