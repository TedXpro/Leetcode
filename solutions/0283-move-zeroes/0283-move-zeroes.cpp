class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, end = 1;
        for(; end < nums.size(); start++, end++){
            if(nums[start] == 0){
                while(end < nums.size() && nums[end] == 0)
                    end++;
                if(end >= nums.size())
                    break;
                swap(nums[start], nums[end]);
            }
        }
    }
};