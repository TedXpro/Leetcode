class Solution {
    bool isMagic(vector<vector<int>>& grid, int row, int col){
        vector<bool> seen(10, false);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int curr = grid[row + i][col + j];
                if(curr < 1 || curr > 9){
                    return false;
                } else if(seen[curr]){
                    return false;
                }
                seen[curr] = true;
            }
        }

        int diag1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diag2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        if(diag1 != diag2){
            return false;
        }

        int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        int row2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2];
        int row3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2];
        if(row1 != diag1 || row2 != diag1 || row3 != diag1){
            return false;
        }

        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        int col2 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1];
        int col3 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2];
        if(col1 != diag1 || col2 != diag1 || col3 != diag1){
            return false;
        }
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int answer = 0;
        for(int row = 0; row + 2 < grid.size(); row++){
            for(int col = 0; col + 2 < grid[0].size(); col++){
                if(isMagic(grid, row, col)){
                    answer++;
                }
            }
        }
        return answer;
    }
};