class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<vector<int>> dp(m, vector<int>(n));

        for(int row = 1; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){
                if(col == 0)
                    matrix[row][col] = matrix[row][col] + min(matrix[row - 1][col], matrix[row - 1][col + 1]);
                else if(col == matrix[0].size() - 1)
                    matrix[row][col] = matrix[row][col] + min(matrix[row - 1][col], matrix[row - 1][col - 1]);
                else{
                    int n = min(matrix[row - 1][col - 1], matrix[row - 1][col]);
                    matrix[row][col] = matrix[row][col] + min(n, matrix[row - 1][col + 1]);
                }
            }
        }

        int mini = INT_MAX;
        for(int row = matrix.size() - 1; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){
                if(matrix[row][col] < mini)
                    mini = matrix[row][col];
            }
        }
        return mini;

    }
};