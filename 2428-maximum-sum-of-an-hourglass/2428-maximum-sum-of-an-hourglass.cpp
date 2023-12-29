class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int maximum = 0;
        for(int row = 0; row < grid.size() - 2; row++){
            for(int col = 0; col < grid[row].size() - 2; col++){
                int subMax = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]+ 
                grid[row + 1][col + 1] + grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];
                maximum = max(maximum, subMax);
            }
        }
        return maximum;
    }
};