# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
*   **`get(key)`**: **O(1)**. Dictionary lookup is O(1). Removing a node from the Doubly Linked List (DLL) and re-inserting it at the head involves only pointer updates, which are O(1).
*   **`put(key, value)`**: **O(1)**. Dictionary insertion/update is O(1). DLL operations (add/remove) are O(1). Eviction (if capacity is exceeded) involves removing the tail node and deleting from the dictionary, both O(1).

### Space Complexity
*   **Auxiliary Space**: **O(C)**, where **C** is the `capacity` of the cache. The dictionary stores at most `C` key-node pairs, and the DLL stores `C` nodes.
*   **Return Space**: **O(1)** (excluding the space required to store the cache itself).

### Algorithmic Invariant
*   **Hash Map + Doubly Linked List**: The solution maintains a **LRU (Least Recently Used) ordering** by keeping the most recently accessed items at the head of the DLL and the least recently accessed items at the tail. The Hash Map provides O(1) access to any node in the DLL, while the DLL allows O(1) reordering and deletion.

### Edge Cases Handled
*   **Capacity = 1**: Correctly handles single-element cache eviction.
*   **Key Update**: `put` correctly updates the value of an existing key and moves it to the head.
*   **Cache Miss**: `get` correctly returns -1 for non-existent keys.
*   **Eviction**: Correctly identifies the least recently used node via `self.tail.prev` and removes it when `len(cache) > capacity`.
*   **Redundant Operations**: The `if self.tail.prev is not self.head` check prevents errors if the cache is empty during eviction.

### Optimization / Alternatives
*   **Micro-optimization**: The `moveToHead` method in the provided code is defined but never used; the logic is split into `remove` and `add_first`. Consolidating these into a single `move_to_head` method would reduce code duplication.
*   **Standard Library**: In Python, `collections.OrderedDict` is the idiomatic way to implement an LRU cache. It internally maintains a hash map and a doubly linked list, allowing `move_to_end` and `popitem(last=False)` to perform the same logic in O(1).
*   **Sentinel Nodes**: The use of dummy `head` and `tail` nodes is an excellent practice; it eliminates the need for null-pointer checks when adding or removing nodes, significantly simplifying the logic.
