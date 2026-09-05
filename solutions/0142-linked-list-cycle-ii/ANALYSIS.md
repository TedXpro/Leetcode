# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**O(N)**, where $N$ is the number of nodes in the linked list.
1. **Phase 1 (Cycle Detection):** The `fast` pointer moves twice as fast as `slow`. If a cycle exists, they meet within $N$ steps.
2. **Phase 2 (Cycle Start):** After meeting, resetting `fast` to `head` and moving both at the same speed takes at most $N$ steps to reach the entry point of the cycle.
3. Total operations are proportional to $2N$, simplifying to $O(N)$.

### Space Complexity
**O(1)** (Auxiliary).
* The algorithm uses only two pointer variables (`slow`, `fast`) regardless of the input size.
* No additional data structures (like hash sets) are used, making it optimal in terms of space.

### Algorithmic Invariant
**Floyd’s Cycle-Finding Algorithm (Tortoise and Hare).**
* The core invariant relies on the mathematical property: if the distance from the head to the cycle start is $L$, the cycle length is $C$, and the meeting point is $k$ steps into the cycle, then $L = nC - k$. By resetting one pointer to the head and moving both at speed 1, they are guaranteed to collide exactly at the cycle's entry point.

### Edge Cases Handled
* **Empty List (`head is None`):** The `while` loop condition `fast and fast.next` fails immediately; returns `None`.
* **Single Node (No Cycle):** `fast.next` is `None`; loop terminates; returns `None`.
* **Single Node (Cycle to self):** `fast` and `slow` meet at the head; returns `head`.
* **No Cycle:** `fast` reaches the end of the list; returns `None`.

### Optimization / Alternatives
* **Hash Set Approach:** Storing visited nodes in a `set()` would achieve $O(N)$ time but requires **O(N) space**. This is less optimal but more intuitive.
* **Micro-optimizations:** The current implementation is already highly optimized. The only potential change is stylistic (e.g., using a `while True` loop with an internal break), but the current structure is standard and readable.
* **Modification (Destructive):** If the problem allowed modifying the input, one could reverse the list or change `next` pointers to detect the cycle, but this is generally discouraged as it violates the integrity of the input data structure.
