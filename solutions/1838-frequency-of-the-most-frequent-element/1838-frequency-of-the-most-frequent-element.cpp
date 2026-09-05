class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxFreq = 1, currFreq = 0;
        int rightPtr = nums.size() - 1;
        int leftPtr = rightPtr;
        while(leftPtr >= 0){
            int diff = nums[rightPtr] - nums[leftPtr];
            if(k - diff < 0){
                k += (nums[rightPtr] - nums[rightPtr - 1]) * (rightPtr - leftPtr - 1);
                maxFreq = max(maxFreq, currFreq);
                currFreq--;
                rightPtr--;
                continue;
            }
            k -= diff;
            currFreq++;
            leftPtr--;
        }

        return max(maxFreq, currFreq);
    }
};