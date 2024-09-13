/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* nodeptr, vector<int>& nums){
        if(nodeptr){
            dfs(nodeptr->left, nums);
            nums.push_back(nodeptr->val);
            dfs(nodeptr->right, nums);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        dfs(root, nums);

        if(nums.size() == 2){
            return !(nums[0] >= nums[1]);
        }
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i - 1] >= nums[i] || nums[i] >= nums[i + 1]){
                return false;
            }
        }
        return true;
    }
};