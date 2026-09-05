class Solution {
private:
    int findMinDistance(unordered_map<int, vector<int>> &graph, int n, int curr, unordered_map<int, int>& memo){
        if(curr == n - 1){
            return 0;
        }

        if(memo.find(curr) != memo.end()){
            return memo[curr];
        }

        int minDistance = n;
        for(int adj : graph[curr]){
            minDistance = min(minDistance, 1 + findMinDistance(graph, n, adj, memo));
        }

        return memo[curr] = minDistance;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, int> memo;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n - 1; i++){
            graph[i].push_back(i + 1);
        }    

        vector<int> answer;
        for(auto &q : queries){
            graph[q[0]].push_back(q[1]);

            answer.push_back(findMinDistance(graph, n, 0, memo));
            memo.clear();
        }

        return answer;
    }
};