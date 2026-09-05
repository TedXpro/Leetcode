class Solution {
private:
    long long maxSum(int index, int even, vector<int>&nums, int &k, vector<vector<long long>>&memo){
        if(index == nums.size())
            return even == 1 ? 0 : INT_MIN;
        if(memo[index][even] != -1)
            return memo[index][even];

            long long val = nums[index] + maxSum(index + 1, even, nums, k, memo);
            long long xorVal = (nums[index] ^ k) + maxSum(index + 1, even ^ 1, nums, k, memo);
            return memo[index][even] = max(val, xorVal);
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
        return maxSum(0, 1, nums, k, memo);
    }
};