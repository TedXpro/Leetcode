class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curr = 1;
        for(int i = 0; i < nums.size();){
            if(curr > nums[i]){
                i++;
                continue;
            }

            if(curr <= nums[i] && nums.size() - i == curr)
                return curr;
            else if(curr > nums.size() - i)
                break;
            curr++;
        }
        return -1;
    }
};