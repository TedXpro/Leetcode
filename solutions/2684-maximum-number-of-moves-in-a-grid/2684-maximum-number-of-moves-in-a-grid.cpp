class Solution {
    const vector<int> DIRS = {-1, 0, 1};
    int dfsTraverse(vector<vector<int>>&grid, int row, int col, unordered_map<string, int>& memo){
        string key = to_string(row) + "," + to_string(col);
        if(memo.find(key) != memo.end()){
            return memo[key];
        }

        int currMax = 0;
        for (const int & dir : DIRS){
            int currRow = row + dir, currCol = col + 1;
            
            if(currRow >= 0 && currRow < grid.size() && currCol >= 0 && 
            currCol < grid[0].size() && grid[row][col] < grid[currRow][currCol]){
                currMax = max(currMax, 1 + dfsTraverse(grid, currRow, currCol, memo));
            }
        }

        return memo[key] = currMax;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        unordered_map<string, int> memo;
        int answer = 0;
        for(int i = 0; i < grid.size(); i++){
            int curr = dfsTraverse(grid, i, 0, memo);
            answer = max(answer, curr);
        }

        return answer;
    }
};