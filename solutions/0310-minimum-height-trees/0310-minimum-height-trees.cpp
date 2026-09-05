class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Edge case: single node
        
        vector<unordered_set<int>> graph(n);
        vector<int> degree(n, 0);

        // Construct the graph and calculate degrees
        for (const auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        // Initialize a queue with leaf nodes
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }

        // Remove leaf nodes iteratively
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;

            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();

                for (int neighbor : graph[leaf]) {
                    // Update degree and add new leaf nodes to the queue
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        // Remaining nodes in the queue are the centers of minimum height trees
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};
