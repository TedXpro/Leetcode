class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> memo;
        long long currSum = 0;
        long long answer = 0;
        int count = 0;
        int left = 0, right = 0;
        while(right < nums.size()) {
            
            int lastOcc = (memo.count(nums[right]) ? memo[nums[right]] : -1);
            while(left <= lastOcc || right - left + 1 > k){
                currSum -= nums[left++];
            }

            memo[nums[right]] = right;
            currSum += nums[right];
            if(right - left + 1 == k){
                answer = max(answer, currSum);
            }
            right++;
        }
        return answer;
    }
};