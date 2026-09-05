class Solution {
private:
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> answer;

    void dfs(int currNode, int parent) {
        for (int &child : graph[currNode]) {
            if (child != parent) {
                dfs(child, currNode);
                count[currNode] += count[child];
                answer[currNode] += answer[child] + count[child];
            }
        }
    }

    void adjustAnswer(int currNode, int parent) {
        for (int &child : graph[currNode]) {
            if (child != parent) {
                answer[child] = answer[currNode] - count[child] + (count.size() - count[child]);
                adjustAnswer(child, currNode);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.clear();
        count = vector<int>(n, 1);
        answer = vector<int>(n, 0);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        adjustAnswer(0, -1);

        return answer;
    }
};