class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        unordered_set<string> seen;
        vector<vector<int>> directions = {{0,1}, {1,0}, {0, -1}, {-1,0}};
        int index = 0;
        int row = 0, col = 0, m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < m * n; i++){
            string key = to_string(row) + "," + to_string(col);
            if(seen.find(key) != seen.end())
                index = (index + 1) % 4;
                
            answer.push_back(matrix[row][col]);
            seen.insert(key);

            int nextRow = row + directions[index][0];
            int nextCol = col + directions[index][1];
            string nextKey = to_string(nextRow) + "," + to_string(nextCol);
            if(nextRow < 0 || nextCol < 0 || nextRow >= m || nextCol >= n || seen.find(nextKey) != seen.end())
                index = (index + 1) % 4;

            row += directions[index][0];
            col += directions[index][1];
        }
        return answer;
    }
};