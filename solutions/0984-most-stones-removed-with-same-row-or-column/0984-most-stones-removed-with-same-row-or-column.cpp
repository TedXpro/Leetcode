class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i){
        visited[i] = true;
        for(int v : graph[i]){
            if(!visited[v]){
                dfs(graph, visited, v);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<vector<int>> graph(stones.size());
        for(int i = 0; i < stones.size(); i++){
            for(int j = i + 1; j < stones.size(); j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int conn = 0;
        vector<bool> visited(stones.size(), false);
        for(int i = 0; i < stones.size(); i++){
            if(!visited[i]){
                dfs(graph, visited, i);
                conn++;
            }
        }

        return stones.size() - conn;
    }
};