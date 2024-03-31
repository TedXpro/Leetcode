class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minIndex = -1, maxIndex = -1, index = -1;
        long long answer = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK)
                index = i;
            
            if(nums[i] == minK)
                minIndex = i;
            
            if(nums[i] == maxK)
                maxIndex = i;

            answer += max(0, min(minIndex, maxIndex) - index);
        }

        return answer;
    }
};