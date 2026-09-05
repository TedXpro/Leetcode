class Solution {
private:
    const vector<vector<int>> DIRECTIONS = {{1,0}, {-1, 0}, {0,-1}, {0, 1}};
    int dfs(vector<vector<int>> &grid, int row, int col){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0)
            return 0;
        
        int maxGold = 0;
        int currValue = grid[row][col];
        grid[row][col] = 0;
        for(int dir = 0; dir < 4; dir++)
            maxGold = max(maxGold, dfs(grid, row + DIRECTIONS[dir][0], col + DIRECTIONS[dir][1]));
        grid[row][col] = currValue;
        return maxGold + currValue;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int answer = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++)
                answer = max(answer, dfs(grid, row, col));
        }
        return answer;
    }
};