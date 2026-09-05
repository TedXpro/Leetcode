class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n, 0));

        int guard = 1; 
        int wall = 2;
        int occupied = 3;

        for(vector<int> g : guards)
            grid[g[0]][g[1]] = guard;
        for(vector<int> w : walls)
            grid[w[0]][w[1]] = wall;

        for(int row = 0; row < m; row++){
            int current = 0;
            for(int col = 0; col < n; col++){
                if(grid[row][col] == guard)
                    current = occupied;
                else if(grid[row][col] == wall)
                    current = 0;
                else if(grid[row][col] == 0){
                    if(current == occupied)
                        grid[row][col] = occupied;
                }
            }
        }

        for(int row = 0; row < m; row++){
            int current = 0;
            for(int col = n - 1; col >= 0; col--){
                if(grid[row][col] == guard)
                    current = occupied;
                else if(grid[row][col] == wall)
                    current = 0;
                else if(grid[row][col] == 0){
                    if(current == occupied)
                        grid[row][col] = occupied;
                }
            }
        }

        for(int col = 0; col < n; col++){
            int current = 0;
            for(int row = 0; row < m; row++){
                if(grid[row][col] == guard)
                    current = occupied;
                else if(grid[row][col] == wall)
                    current = 0;
                else if(grid[row][col] == 0){
                    if(current == occupied)
                        grid[row][col] = occupied;
                }
            }
        }

        for(int col = 0; col < n; col++){
            int current = 0; 
            for(int row = m - 1; row >= 0; row--){
                if(grid[row][col] == guard)
                    current = occupied;
                else if(grid[row][col] == wall)
                    current = 0;
                else if(grid[row][col] == 0){
                    if(current == occupied)
                        grid[row][col] = occupied;
                }
            }
        }

        int count = 0;
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0)
                    count++;
            }
        }
        return count;

    }
};