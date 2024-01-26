class Solution {
    const int MOD = 1e9 + 7;
    int calculate(int m, int n, int row, int col, int moveLeft, vector<vector<vector<int>>>& memo){
        if(row < 0 || col < 0 || row >= m || col >= n)
            return 1;
        
        if(moveLeft == 0)
            return 0;

        if(memo[row][col][moveLeft] != -1)
            return memo[row][col][moveLeft];

        long res = 0;
        res += calculate(m, n, row + 1, col, moveLeft - 1, memo);
        res += calculate(m, n, row - 1, col, moveLeft - 1, memo);
        res += calculate(m, n, row, col - 1, moveLeft - 1, memo);
        res += calculate(m, n, row, col + 1, moveLeft - 1, memo);

        memo[row][col][moveLeft] = res % MOD; 
        return memo[row][col][moveLeft];
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return calculate(m, n, startRow, startColumn, maxMove, memo);
    }
};
