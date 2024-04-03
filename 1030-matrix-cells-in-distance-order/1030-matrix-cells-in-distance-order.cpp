class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> answer;
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int distance = abs(row - rCenter) + abs(col - cCenter);
                vector<int> ans = {distance, row, col};
                answer.push_back(ans);
            }
        }

        sort(answer.begin(), answer.end());
        vector<vector<int>> result;
        for(vector<int>& ans : answer){
            result.push_back({ans.begin() + 1, ans.end()});
        }
        return result;
    }
};