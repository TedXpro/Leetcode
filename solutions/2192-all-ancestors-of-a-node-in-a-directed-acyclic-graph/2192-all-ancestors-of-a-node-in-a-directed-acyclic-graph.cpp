class Solution {
    void bfs(vector<vector<int>> &answer, map<int, vector<int>> &graph, int node){
        queue<int> q;
        q.push(node);
        unordered_set<int> visited;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 0; i < graph[curr].size(); i++){
                if(visited.find(graph[curr][i]) == visited.end()){
                    if(answer[graph[curr][i]].size() == 0)
                        answer[graph[curr][i]].push_back(node);
                    else if(answer[graph[curr][i]].size() != 0 && answer[graph[curr][i]].back() != node){
                        answer[graph[curr][i]].push_back(node);
                    }
                    q.push(graph[curr][i]);
                }
            }
            visited.insert(curr);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> graph;
        for(vector<int> &edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> answer(n);
        for(auto &curr : graph){

            bfs(answer, graph, curr.first);
        }

        return answer;
    }
};