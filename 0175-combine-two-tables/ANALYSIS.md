# Complexity & Algorithmic Analysis


## Pythondata Analysis

> *Reviewed with `gemini-3.1-flash-lite`*

### Time Complexity
**$O(N + M)$**
*   **Merging:** `pd.merge` uses a hash-based join (typically $O(N + M)$ where $N$ is the number of rows in `person` and $M$ is the number of rows in `address`).
*   **Column Selection:** Selecting specific columns is $O(K)$, where $K$ is the number of rows in the resulting dataframe.
*   Total: $O(N + M)$.

### Space Complexity
**$O(N + M)$**
*   **Auxiliary Space:** $O(N + M)$ to store the intermediate merged dataframe before filtering.
*   **Return Space:** $O(N)$ to store the final result containing the `firstName`, `lastName`, `city`, and `state` columns for all $N$ entries in the `person` table.

### Algorithmic Invariant
**Hash Join:** The solution utilizes a hash-based join strategy. By mapping the `personId` keys from the `address` table into a hash table, the algorithm achieves linear time complexity to match records with the `person` table.

### Edge Cases Handled
*   **Missing Addresses:** The `how="left"` parameter ensures that if a `personId` exists in `person` but not in `address`, the result retains the person's name with `NaN` values for `city` and `state`.
*   **Empty Tables:** If the `person` table is empty, the result is an empty dataframe with the specified columns.
*   **Duplicate IDs:** If `address` contains multiple entries for the same `personId`, the merge will produce a Cartesian product for those specific IDs (though standard schema constraints usually imply a 1:1 or 1:0 relationship).

### Optimization / Alternatives
*   **Memory Efficiency:** If the `address` table is significantly larger than the `person` table, filtering the `address` columns *before* the merge (`address[['personId', 'city', 'state']]`) can reduce memory overhead.
*   **In-place Operations:** While Pandas is generally immutable for these operations, using `copy=False` (where applicable in internal methods) can slightly reduce memory allocation.
*   **Alternative:** For massive datasets, using `dask` or `polars` would provide better performance via lazy evaluation and multi-threaded execution, though `pandas` is the standard for this specific LeetCode environment.
