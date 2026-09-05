class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        for(;right < nums.size(); right++){
            if(left + 1 < nums.size() && nums[left] != nums[right]){
                nums[left + 1] = nums[right];
                left++;
            }
        }        
        return left + 1;
    }
};