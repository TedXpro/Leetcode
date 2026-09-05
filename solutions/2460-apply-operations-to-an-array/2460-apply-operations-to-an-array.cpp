class Solution {
private:
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
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int start = 1; start < nums.size(); start++){
            if(nums[start] == nums[start - 1]){
                nums[start] = 0;
                nums[start - 1] *= 2;
            }
        }

        moveZeroes(nums);
        return nums;
    }
};