class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int start = 0, end = 1;
        for(; end < nums.size(); start++, end++){
            if(nums[start] == nums[end]){
                count++;
                nums[end]++;
            } else if(nums[start] > nums[end]){
                count += nums[start] - nums[end] + 1;
                nums[end] = nums[start] + 1;
            }
        }

        return count;
    }
};