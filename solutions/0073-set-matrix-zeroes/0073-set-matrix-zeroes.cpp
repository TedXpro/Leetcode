class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> rowMemo;
        unordered_set<int> colMemo;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(matrix[row][col] == 0){
                    rowMemo.insert(row);
                    colMemo.insert(col);
                }
            }
        }

        for(const int &row : rowMemo){
            for(int col = 0; col < n; col++)
                matrix[row][col] = 0;
        }

        for(const int &col : colMemo){
            for(int row = 0; row < m; row++)
                matrix[row][col] = 0;
        }
    }
};