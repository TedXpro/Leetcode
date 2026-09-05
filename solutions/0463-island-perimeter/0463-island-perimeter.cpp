class Solution {
    int dfs(vector<vector<int>> &grid, int row, int col, unordered_set<string>& memo){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
            return 1;
        string key = to_string(row) + "," + to_string(col);
        if(memo.find(key) != memo.end())
            return 0;

        memo.insert(key);
        int answer = dfs(grid, row - 1, col, memo) + 
            dfs(grid, row, col - 1, memo) + 
            dfs(grid, row + 1, col, memo) + 
            dfs(grid, row, col + 1, memo);
        return answer;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        unordered_set<string> memo;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == 1)
                    return dfs(grid, row, col, memo);
            }
        }

        return 0;
    }
};