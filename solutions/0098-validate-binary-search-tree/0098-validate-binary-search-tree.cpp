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
    bool dfs(TreeNode* nodeptr, TreeNode* low, TreeNode* high){
        if(nodeptr){
            if((low && nodeptr->val <= low->val) || (high && nodeptr->val >= high->val)){
                return false;
            }

            return dfs(nodeptr->left, low, nodeptr) && dfs(nodeptr->right, nodeptr, high);
        }

        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};