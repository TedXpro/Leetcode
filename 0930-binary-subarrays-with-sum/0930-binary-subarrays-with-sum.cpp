class Solution {
private:   
    int findTotal(vector<int>& nums, int goal){
        int start = 0, currSum = 0, totCount = 0;
        for(int end = 0; end < nums.size(); end++){
            currSum += nums[end];

            while(start <= end && currSum > goal){
                currSum -= nums[start];
                start++;
            }

            totCount += end - start + 1;
        }
        return totCount;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findTotal(nums, goal) - findTotal(nums, goal - 1);
    }
};