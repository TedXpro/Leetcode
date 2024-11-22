class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> memo;
        for(auto& mat : matrix){
            string currPattern = "";
            for(int col = 0; col < mat.size(); col++){
                if(mat[0] == mat[col]){
                    currPattern += 'X';
                } else {
                    currPattern += 'O';
                }
            }

            memo[currPattern]++;
        }

        int answer = 0;
        for(auto curr : memo){
            answer = max(answer, curr.second);
        }

        return answer;
    }
};