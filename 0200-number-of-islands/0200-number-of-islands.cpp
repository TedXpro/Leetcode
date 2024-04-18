class Solution {
    void countIslands(vector<vector<char>> &grid, int row, int col, unordered_set<string> &memo){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
            return;
        string key = to_string(row) + "," + to_string(col);
        if(memo.find(key) != memo.end())
            return;
        memo.insert(key);
        countIslands(grid, row - 1, col, memo);
        countIslands(grid, row, col - 1, memo);
        countIslands(grid, row + 1, col, memo);
        countIslands(grid, row, col + 1, memo);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_set<string> memo;
        int answer = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                string key = to_string(row) + "," + to_string(col);
                if(grid[row][col] != '0' && memo.find(key) == memo.end()){
                    answer++;
                    countIslands(grid, row, col, memo);
                }
            }
        }

        return answer;
    }
};