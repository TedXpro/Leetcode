class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int size = mat.size();
        int answer = 0;

        for(int i = 0; i < size; i++){
            answer += mat[i][i];
            answer += mat[size - 1 - i][i];
        }

        if(size % 2 != 0)
            answer -= mat[size / 2][size / 2];
        return answer;
    }
};