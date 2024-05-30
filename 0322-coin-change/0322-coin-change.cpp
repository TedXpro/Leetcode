class Solution {
    int dp(vector<int>& coins, int amount, unordered_map<int, int> &memo){
        if(memo.find(amount) != memo.end())
            return memo[amount];
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        
        int minCost = INT_MAX - 1;
        for(int coin : coins){
            int currCost = dp(coins, amount - coin, memo);
            if(currCost == -1)
                continue;
            
            minCost = min(minCost, currCost + 1);
        }

        return memo[amount] = minCost == INT_MAX - 1 ? -1 : minCost;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        return dp(coins, amount, memo);
    }
};