class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowIndex = 0, fastIndex = 0;
        while(true){
            slowIndex = nums[slowIndex];
            fastIndex = nums[nums[fastIndex]];
            if(slowIndex == fastIndex)
                break;
        }

        int index = 0;
        while(true){
            index = nums[index];
            slowIndex = nums[slowIndex];
            if(slowIndex == index)
                return index;
        }
    }
};