class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int answer = 0;
        for(int row = 0; row < grid.size(); row++){
            if(grid[row][0] == 0){
                for(int col = 0; col < grid[0].size(); col++)
                    grid[row][col] = grid[row][col] == 0 ? 1 : 0;
            }
        }
    
        for(int col = 1; col < grid[0].size(); col++){
            int zeros = 0;
            for(int row = 0; row < grid.size(); row++)
                zeros += grid[row][col] == 0 ? 1 : 0;
            if(zeros > grid.size() - zeros){
                for(int row = 0; row < grid.size(); row++)
                    grid[row][col] = grid[row][col] == 0 ? 1 : 0;
            }
        }

        for(vector<int>& row : grid){
            int score = 0;
            for(int col = 0; col < row.size(); col++){
                score += row[col] * pow(2, row.size() - col - 1);
            }
            answer += score;
        }

        return answer;
    }
};