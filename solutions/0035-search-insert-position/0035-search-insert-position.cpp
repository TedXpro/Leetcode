class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0,
            last = nums.size() - 1,
            middle,
            position;

        while(first <= last)
        {
            middle = (first + last) / 2;
            if(target == nums[middle])
            {
                position = middle;
                break;
            }
            else if(nums[middle] > target)
            {
                position = first;
                last = middle - 1;
            }
            else
            {
                position = first + 1;
                first = middle + 1;
            }
        }
        
        return position;
    }
};