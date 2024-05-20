class Solution {
    int dfs(vector<int>& nums, int index, int currXor){
        if(index == nums.size())
            return currXor;
        int curr = dfs(nums, index + 1, currXor ^ nums[index]);
        int notInclude = dfs(nums, index + 1, currXor);
        return curr + notInclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};