class Solution {
    void countIslands(vector<vector<char>> &grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
            return;
        grid[row][col] = '0';
        countIslands(grid, row - 1, col);
        countIslands(grid, row, col - 1);
        countIslands(grid, row + 1, col);
        countIslands(grid, row, col + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] != '0'){
                    answer++;
                    countIslands(grid, row, col);
                }
            }
        }

        return answer;
    }
};