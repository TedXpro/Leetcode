class Solution {
private:
    int traverse(int i, int j, vector<vector<int>>& matrix, unordered_map<string, int>&memo){
        if(i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        if(matrix[i][j] == 0){
            return 0;
        }

        string key = to_string(i) + "," + to_string(j);
        if(memo.find(key) != memo.end()){
            return memo[key];
        }

        int right = traverse(i, j + 1, matrix, memo);
        int diagonal = traverse(i + 1, j + 1, matrix, memo);
        int below = traverse(i + 1, j, matrix, memo);

        return memo[key] = 1 + min(right, min(diagonal, below));
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        unordered_map<string, int> memo;
        int count = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                count += traverse(i, j, matrix, memo);
            }
        }

        return count;
    }
};