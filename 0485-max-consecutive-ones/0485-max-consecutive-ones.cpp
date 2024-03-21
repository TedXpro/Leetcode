class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        int i = 0;
        for(; i < nums.size(); i++){
            if(nums[i] == 0){
                maxCount = max(maxCount, count);
                count = 0;
            } else 
                count++;
        }

        maxCount = max(maxCount, count);

        return maxCount;
    }
};