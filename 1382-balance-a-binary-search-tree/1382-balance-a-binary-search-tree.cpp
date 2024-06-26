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
    void traverse(TreeNode* node, vector<int>& nums){
        if(node){
            traverse(node->left, nums);
            nums.push_back(node->val);
            traverse(node->right, nums);
        }
    }

    TreeNode* construct(vector<int> nums, int start, int end){
        if(start > end)
            return nullptr;
        
        int mid = start + (end - start) / 2;
        TreeNode* leftSub = construct(nums, start, mid - 1);
        TreeNode* rightSub = construct(nums, mid + 1, end);

        return new TreeNode(nums[mid], leftSub, rightSub);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        traverse(root, nums);
        return construct(nums, 0, nums.size() - 1);
    }
};