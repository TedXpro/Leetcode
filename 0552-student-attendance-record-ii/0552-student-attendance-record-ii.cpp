class Solution {
private:
    const int MOD = 1000000007;
    int findRecords(int n, int absent, int late, vector<vector<vector<int>>> &memo){
        if(absent >= 2 || late >= 3)
            return 0;
        if(n == 0)
            return 1;
        // string key = to_string(n) + "," + to_string(absent) + "," + to_string(late);
        // if(memo.find(key) != memo.end())
            // return memo[key];
        if(memo[n][absent][late] != -1)
            return memo[n][absent][late];
        
        int currCount = 0;
        currCount = findRecords(n - 1, absent, 0, memo); // choose P
        currCount = (currCount +  findRecords(n - 1, absent + 1, 0, memo)) % MOD; // choose A
        currCount = (currCount + findRecords(n - 1, absent, late + 1, memo)) % MOD; // choose L

        memo[n][absent][late] = currCount;
        return currCount;
    }
public:
    int checkRecord(int n) {
        // unordered_map<string, int> memo;
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return findRecords(n, 0, 0, memo);
    }
};