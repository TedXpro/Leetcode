class Solution {
    // bool jump(vector<int>& nums, int index, unordered_map<int, bool>& memo){
    //     if(index == nums.size() - 1)
    //         return true;
    //     if(index >= nums.size())
    //         return false;
    //     if(memo.find(index) != memo.end())
    //         return memo[index];

    //     bool possible = false;
    //     for(int i = 1; i <= nums[index]; i++){
    //         possible = jump(nums, index + i, memo);
    //         if(possible){
    //             memo[index] = possible;
    //             return true;
    //         }
    //     }

    //     memo[index] = possible;
    //     return possible;
    // }
public:
    bool canJump(vector<int>& nums) {
        // unordered_map<int, bool> memo;
        // return jump(nums, 0, memo);

        bool isValid = true;
        int jump = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] >= jump){
                isValid = true;
                jump = 1;
            } else{
                isValid = false;
                jump++;
            }

        }
        return isValid;
    }
};