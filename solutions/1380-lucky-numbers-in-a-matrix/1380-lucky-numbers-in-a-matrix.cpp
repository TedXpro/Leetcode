class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols(matrix[0].size(), INT_MIN + 1);

        int rowCount = 0;
        for(vector<int> & mat : matrix){
            int currMin = INT_MAX;
            for(int i = 0; i < mat.size(); i++){
                currMin = min(currMin, mat[i]);
                cols[i] = max(cols[i], mat[i]);
            }
            rows.push_back(currMin);
            // rows[rowCount] = min(rows[rowCount], currMin);
        }
        vector<int> answer;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == rows[i] && matrix[i][j] == cols[j]) {
                    answer.push_back(matrix[i][j]);
                }
            }
        }  
        return answer;  
    }
};