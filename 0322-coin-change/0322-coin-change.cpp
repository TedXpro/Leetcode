class Solution {
    int findMinCoins(vector<int>& coins, int amount, unordered_map<int, int> &memo){
        if(memo.find(amount) != memo.end())
            return memo[amount];
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        
        int minCoins = INT_MAX - 1;
        for(int coin : coins){
            int curr = findMinCoins(coins, amount - coin, memo);
            if(curr == -1)
                continue;
            minCoins = min(minCoins, curr + 1);
        }
        int answer = minCoins == INT_MAX - 1? -1 : minCoins;
        memo[amount] = answer;
        return answer;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        return findMinCoins(coins, amount, memo);
    }
};