class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> memo;
        memo[5] = 0;
        memo[10] = 0;
        memo[20] = 0;

        for(int i = 0; i < bills.size(); i++){
            memo[bills[i]]++;
            int change = bills[i] - 5;
            if(change == 5){
                if(memo[5] == 0)
                    return false;
                memo[5]--;
            } else if(change == 15){
                if(memo[5] != 0 && memo[10] != 0){
                    memo[5]--;
                    memo[10]--;
                } else if( memo[5] >= 3)
                    memo[5] -= 3;
                else 
                    return false;
                
            }
        }
        return true;
    }
};