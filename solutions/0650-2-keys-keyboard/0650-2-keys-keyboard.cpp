class Solution {
    int recur(int curr, int paste, int &n, unordered_map<string, int>& memo) {
        if(curr == n){
            return 0;
        }

        if(curr > n){
            return 1000;
        }
        string key = to_string(curr) + "," + to_string(paste);
        if(memo.find(key) != memo.end()){
            return memo[key];
        }

        int val1 = 2 + recur(curr * 2, curr, n, memo);
        int val2 = 1 + recur(curr + paste, paste, n, memo);

        memo[key] =  min(val1, val2);
        return memo[key];
    }
public:
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }
        
        unordered_map<string, int> memo;
        return 1 + recur(1, 1, n, memo);
    }
};