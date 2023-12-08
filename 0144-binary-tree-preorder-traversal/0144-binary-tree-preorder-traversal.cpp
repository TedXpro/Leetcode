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
    vector<int> preOrder;

    void preOrderTraverse(TreeNode* node){
        if(node){
            preOrder.push_back(node->val);
            preOrderTraverse(node->left);
            preOrderTraverse(node->right);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preOrderTraverse(root);
        return preOrder;
    }
};