class Solution {
    int findLocalMax(vector<vector<int>> &grid, int row, int col){
        int maxi = 0;
        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++)
                maxi = max(maxi, grid[i][j]);
        }
        return maxi;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> answer(grid.size() - 2, vector<int>(grid.size() - 2, 0));
        for(int i = 0; i < grid.size() - 2; i++){
            for(int j = 0; j < grid.size() - 2; j++)
                answer[i][j] = findLocalMax(grid, i, j);
        }

        return answer;
    }
};