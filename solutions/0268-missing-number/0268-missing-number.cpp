class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedTotal = (nums.size() * (nums.size() + 1)) / 2;
        int currTotal = 0;

        for(int num : nums)
            currTotal += num;
        
        return expectedTotal - currTotal;
    }
};