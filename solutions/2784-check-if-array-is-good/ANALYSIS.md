# Complexity & Algorithmic Analysis


## Python3 Analysis

> *Reviewed with `gemini-3-flash-preview`*

- **Time Complexity**: **$O(n)$**
    - **Step 1**: Calculating $n$ and initializing the `seen` array takes $O(n)$, where $n$ is `len(nums) - 1`.
    - **Step 2**: Iterating through the input array `nums` takes $O(n)$. Each lookup and update in the `seen` array is $O(1)$.
    - **Step 3**: The final loop iterates through the `seen` array up to $n-1$, which is $O(n)$.
    - **Total**: $
