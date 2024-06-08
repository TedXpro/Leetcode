class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> memo;
        memo[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum = (sum + nums[i]) % k;
            if(memo.find(sum) != memo.end()){
                if(i - memo[sum] >= 2)
                    return true;
            } else
                memo[sum] = i;
        }
        return false;
    }
};