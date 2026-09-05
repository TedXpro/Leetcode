class Solution {
    const vector<vector<int>> DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(int m, int n, int row, int col){
        return row >= 0 && col >= 0 && row < m && col < n;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> minObst(m, vector<int>(n, INT_MAX));
        minObst[0][0] = 0;

        deque<array<int, 3>> dq;
        dq.push_back({0, 0, 0});
        while(!dq.empty()){
            auto curr = dq.front();
            dq.pop_front();
            int obst = curr[0], row = curr[1], col = curr[2];

            for(auto& dir : DIR){
                int newRow = row + dir[0], newCol = col + dir[1];
                if(isValid(m, n, newRow, newCol) && minObst[newRow][newCol] == INT_MAX){
                    if(grid[newRow][newCol] == 1){
                        minObst[newRow][newCol] = obst + 1;
                        dq.push_back({obst + 1, newRow, newCol});
                    } else {
                        minObst[newRow][newCol] = obst;
                        dq.push_front({obst, newRow, newCol});
                    }
                }
            }
        }
        return minObst[m - 1][n - 1];
    }
};