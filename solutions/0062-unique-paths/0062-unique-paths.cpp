class Solution {
    int findPaths(int m, int n, unordered_map<string, int> &memo){
        if(m == 1 && n == 1)
            return 1;
        if(m == 0 || n == 0)
            return 0;
        string key = to_string(m) + "," + to_string(n);
        if(memo.find(key) != memo.end())
            return memo[key];
        int sum = findPaths(m, n - 1, memo) + findPaths(m - 1, n, memo);
        memo[key] = sum;
        return sum;
    }
public:
    int uniquePaths(int m, int n) {
        unordered_map<string, int> memo;
        return findPaths(m, n, memo);
    }
};