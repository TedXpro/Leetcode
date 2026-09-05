class Solution {
    const int MOD = 1e9 + 7;
    map<string, int> memo; 
    int calculateWays(int n, int k, int target){
        if(n == 0)
            return target == 0? 1 : 0;
        else if(target <= 0)
            return 0;
        string key = to_string(n) + "," + to_string(target);
        if(memo.contains(key))
            return memo[key];

        int ways = 0;
        for(int i = 1; i <= k; i++){
            ways += (calculateWays(n - 1, k, target - i)); 
            ways %= MOD;
        }
        memo[key] = ways;
        return ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return calculateWays(n, k, target);
    }
};