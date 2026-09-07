# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.5-flash-lite`*

- **Time Complexity**: $O(N)$
  - **Breakdown**: 
    1. Appending `0` to `heights` takes $O(1)$ time.
    2. The `for` loop iterates through each of the $N + 1$ elements exactly once ($O(N)$).
    3. The `while` loop pops elements off the stack. Each index is pushed onto the stack exactly once and popped at most once across the entire execution of the algorithm ($O(N)$ total across all iterations).
    4. Thus, the total time complexity is $O(N) + O(N) = O(N)$.

- **Space Complexity**: $O(N)$
  - **Breakdown**: 
    - **Auxiliary Memory**: The `stack` stores indices of the `heights` array. In the worst-case scenario (e.g., a strictly increasing array of heights), the stack will grow to store all $N+1$ indices, requiring $O(N)$ space.
    - **Return Space**: Uses a few scalar variables (`max_area`, `h`, `width`, `area`), which take $O(1)$ auxiliary memory.
    - **Modifications**: Modifying `heights` in-place by appending `0` takes $O(1)$ auxiliary space.

- **Algorithmic Invariant**: **Monotonic Stack**
  - **Technique**: Maintains a stack of indices corresponding to bar heights in strictly increasing order. When a bar lower than the bar at the top of the stack is encountered, it acts as a "right boundary" that terminates the potential maximum rectangles for the taller bars preceding it, allowing their widths and areas to be computed dynamically.

- **Edge Cases Handled**:
  - **Empty Array (`heights = []`)**: The appended `0` creates `[0]`, the loop runs once, computes area `0`, and returns `0`.
  - **Strictly Increasing / Decreasing Heights**: The appended terminal `0` ensures that all remaining elements in a strictly increasing stack are forcibly popped and evaluated at the end of the array.
  - **Duplicate Heights**: Handled correctly because the strict inequality (`heights[i] < heights[stack[-1]]`) allows equal heights to be safely pushed without prematurely popping valid left boundaries.
  - **Single Element**: Evaluates correctly as `height * 1`.

- **Optimization / Alternatives**:
  - **Micro-optimizations**: Local variable caching (e.g., storing `heights` in a local variable to bypass global lookup overhead in Python) can slightly improve execution speed.
  - **Alternative Approach (Divide and Conquer)**: Finding the minimum height in sub-ranges recursively yields an $O(N \log N)$ average time complexity (or $O(N^2)$ worst-case for sorted inputs), which is strictly inferior to the monotonic stack approach.
  - **Alternative Approach (Previous/Next Smaller Elements)**: Pre-computing Left and Right Smaller Element arrays using two passes with a stack is logically equivalent but uses more memory ($3N$ space) compared to this single-pass inline computation.
