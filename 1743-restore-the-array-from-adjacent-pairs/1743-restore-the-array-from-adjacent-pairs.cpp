class Solution {
    unordered_map<int, vector<int>> graph;
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto& n: adjacentPairs){
            graph[n[0]].push_back(n[1]);
            graph[n[1]].push_back(n[0]);
        }
        
        int root = 0;
        for(auto& pair: graph){
            if(pair.second.size() == 1){
                root = pair.first;
                break;
            }
        }

        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;
    }

    void dfs(int node, int prev, vector<int>& ans){
        ans.push_back(node);
        for(int neighbour : graph[node]){
            if(neighbour != prev)
                dfs(neighbour, node, ans);
        }
    }
};