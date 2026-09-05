# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**O(n)**, where *n* is the length of the strings.
1. **Length check**: O(1).
2. **Single pass loop**: Iterates *n* times, performing constant-time arithmetic and array indexing.
3. **Validation loop**: Iterates exactly 26 times (constant).
4. **Total**: O(n + 26) simplifies to **O(n)**.

### Space Complexity
**O(1)** (Auxiliary).
* The algorithm uses a fixed-size array of 26 integers regardless of the input size *n*. 
* Since the alphabet size is constant (assuming lowercase English letters), the space requirement does not scale with input size.

### Algorithmic Invariant
**Frequency Counting (Hash Map / Frequency Array)**.
The algorithm maintains a net-zero invariant: for two strings to be anagrams, the frequency of each character in `s` must be perfectly offset by the frequency of the same character in `t`. By incrementing for `s` and decrementing for `t`, the final state of the array must be all zeros.

### Edge Cases Handled
* **Length Mismatch**: Handled by the initial `len(s) != len(t)` check, preventing unnecessary processing.
* **Empty Strings**: If both are empty, the length check passes, the loop is skipped, and the function returns `True` (correct).
* **Single Character Strings**: Correctly compares the single character index.
* **Non-Anagrams**: Any discrepancy in character counts results in a non-zero value in the `unique` array, caught by the final validation loop.

### Optimization / Alternatives
* **Micro-optimization**: If the input strings are extremely large and the alphabet is small, this is already optimal. However, using `collections.Counter` would be more "Pythonic" but slightly slower due to dictionary overhead.
* **Sorting**: An alternative approach is `sorted(s) == sorted(t)`, which has a time complexity of **O(n log n)**. This is less efficient but more concise.
* **Unicode Support**: If the input includes non-ASCII characters, the fixed-size array of 26 would fail. A `collections.defaultdict(int)` or a standard `dict` would be required, increasing space complexity to **O(k)**, where *k* is the number of unique characters.
