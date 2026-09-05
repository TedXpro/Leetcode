class Solution {
    bool dfs(unordered_map<int, vector<int>>& graph, int src, int &dst, unordered_set<int>& visited){
        if(src == dst)
            return true;
        if(visited.find(src) != visited.end())
            return false;
        
        visited.insert(src);
        for(int& s : graph[src]){
            if(dfs(graph, s, dst, visited)){
                return true;
            }
        }
        cout << "This one!" << src << endl;
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;

        for(vector<int> & edge : edges){
            // if(graph.find(edge[0]) == graph.end())
                // graph[edge[0]] = vector<int>({edge[1]});
            // else 
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            // if(graph.find(edge[1]) == graph.end())
                // graph[edge[1]] = vector<int>({edge[0]});
            // else 
                // graph[edge[1]]
        }

        return dfs(graph, source, destination, visited);
    }
};