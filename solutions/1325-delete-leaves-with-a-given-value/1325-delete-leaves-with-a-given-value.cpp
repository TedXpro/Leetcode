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
    void deleteNodes(TreeNode*& nodeptr, int &target){
        if(nodeptr){
            deleteNodes(nodeptr->left, target);
            deleteNodes(nodeptr->right, target);
            if(nodeptr->left == nullptr && nodeptr->right == nullptr && nodeptr->val == target){
                nodeptr = nullptr;
            }
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        deleteNodes(root, target);
        return root;
    }
};