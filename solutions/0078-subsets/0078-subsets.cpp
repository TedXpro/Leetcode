class Solution {
    void findSubsets(vector<int>&nums, vector<vector<int>> &memo, vector<int>curr, int currIndex){
        if(currIndex == nums.size()){
            memo.push_back(curr);
            return;
        }
        
        findSubsets(nums, memo, curr, currIndex + 1);
        curr.push_back(nums[currIndex]);
        findSubsets(nums, memo, curr, currIndex + 1);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        findSubsets(nums, answer, vector<int>{}, 0);
        return answer;
    }
};