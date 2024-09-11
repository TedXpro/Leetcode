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
    bool dfs(TreeNode* nodeptr, int &targetSum, int currTotal){
        if(nodeptr){
            currTotal += nodeptr->val;
            if(currTotal == targetSum){
                if(!nodeptr->left && !nodeptr->right){
                    return true;
                }
            }

            return dfs(nodeptr->left, targetSum, currTotal) || dfs(nodeptr->right, targetSum, currTotal);
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};