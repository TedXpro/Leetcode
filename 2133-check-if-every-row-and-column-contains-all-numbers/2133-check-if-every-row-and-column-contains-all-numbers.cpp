class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> rows[n];
        unordered_set<int> columns[n];
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[0].size(); col++){
                if(rows[row].find(matrix[row][col])  != rows[row].end())
                    return false;
                if(columns[col].find(matrix[row][col]) != columns[col].end())
                    return false;
                rows[row].insert(matrix[row][col]);
                columns[col].insert(matrix[row][col]);
            }
        }
        return true;
    }
};