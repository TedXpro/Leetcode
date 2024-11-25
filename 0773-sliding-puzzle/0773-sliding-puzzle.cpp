class Solution {
private:
    void dfs(string state, unordered_map<string, int>& visited, int zeroPos, 
    int moves, unordered_map<int, vector<int>>& memo){
        if(visited.count(state) && visited[state] <= moves){
            return;
        }

        visited[state] = moves;
        for(int nextPos : memo[zeroPos]){
            swap(state[zeroPos], state[nextPos]);
            dfs(state, visited, nextPos, moves + 1, memo);
            swap(state[zeroPos], state[nextPos]);
        }
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, vector<int>> memo;
        memo[0] = {1, 3};
        memo[1] = {0, 2, 4};
        memo[2] = {1, 5};
        memo[3] = {0, 4};
        memo[4] = {3, 5, 1};
        memo[5] = {2, 4};


        string bStr = "";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                bStr += to_string(board[i][j]);
            }
        }

        unordered_map<string, int> visited;

        dfs(bStr, visited, bStr.find('0'), 0, memo);

        return visited.count("123450") ? visited["123450"] : -1;
    }
};