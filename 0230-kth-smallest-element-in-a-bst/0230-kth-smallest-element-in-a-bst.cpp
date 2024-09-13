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
    void inorder(TreeNode* nodeptr, vector<int>& nums){
        if(nodeptr){
            inorder(nodeptr->left, nums);
            nums.push_back(nodeptr->val);
            inorder(nodeptr->right, nums);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        return nums[k - 1];
    }
};