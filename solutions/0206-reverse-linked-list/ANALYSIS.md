# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.5-flash-lite`*

- **Time Complexity**: $O(N)$
  - The `while` loop iterates through each node of the linked list exactly once.
  - Inside the loop, all operations (`nxt = curr.next`, `curr.next = prev`, `prev = curr`, `curr = nxt`) run in $O(1)$ constant time.
  - Thus, for a list of $N$ nodes, the total time complexity is linear, $O(N)$.

- **Space Complexity**: $O(1)$
  - Auxiliary memory: Uses a constant number of pointers (`prev`, `curr`, `nxt`) regardless of the input size, resulting in $O(1)$ auxiliary space.
  - Return space: Modifies the list in-place and returns the existing nodes, requiring no additional data structures.

- **Algorithmic Invariant**: Two Pointers (Iterative Pointer Reversal)
  - Maintains two primary pointers (`prev` and `curr`) to systematically reverse the direction of the `next` pointers one by one, while using a temporary pointer (`nxt`) to prevent loss of the remaining unvisited list.

- **Edge Cases Handled**:
  - **Empty list (`head = None`)**: The `while curr:` loop is bypassed immediately, and `prev` (which is `None`) is returned correctly.
  - **Single-node list (`head.next = None`)**: The loop runs for one iteration, successfully pointing the single node's `next` to `None`, and returns the node as the new head.
  - **Two-node list**: Correctly handles the swapping of pointers and terminates with `prev` pointing to the second node (new head) and `curr` becoming `None`.

- **Optimization / Alternatives**:
  - **Micro-optimizations**: Python allows tuple assignment to swap and advance pointers simultaneously (`prev, curr, curr.next = curr, curr.next, prev`), which makes the code more concise, though it performs similarly under the hood.
  - **Alternative (Recursive)**: Can be implemented recursively with $O(N)$ space due to the call stack:
    ```python
    def reverseList(self, head: Optional[ListNode], prev: Optional[ListNode] = None) -> Optional[ListNode]:
        if not head:
            return prev
        nxt = head.next
        head.next = prev
        return self.reverseList(nxt, head)
    ```
