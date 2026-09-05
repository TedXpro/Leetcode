class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> memo;
        int maxSubarray = 0;
        for(int start = 0, end = 0; end < nums.size(); end++){
            if(memo.find(nums[end]) == memo.end()){
                memo[nums[end]] = 1;
                maxSubarray = max(maxSubarray, end - start + 1);
            }else {
                while(start < end && memo[nums[end]] == k){
                    memo[nums[start]]--;
                    start++;
                }
                memo[nums[end]]++;
                maxSubarray = max(maxSubarray, end - start + 1);
            }
        }

        return maxSubarray;
    }
};