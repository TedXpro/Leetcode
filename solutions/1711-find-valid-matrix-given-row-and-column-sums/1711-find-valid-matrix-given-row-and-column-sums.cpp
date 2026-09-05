class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<int> currRows(rowSum.size(), 0);
        vector<int> currCols(colSum.size(), 0);
        vector<vector<int>> answer(rowSum.size(), vector<int>(colSum.size(), 0));
        for(int i = 0; i < rowSum.size(); i++){
            for(int j = 0; j < colSum.size(); j++){
                answer[i][j] = min(rowSum[i] - currRows[i], colSum[j] - currCols[j]);
                currRows[i] += answer[i][j];
                currCols[j] += answer[i][j];
            }
        }

        return answer;
    }
};