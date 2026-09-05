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
    vector<int> postOrder;

    void postOrderTraverse(TreeNode* node){
        if(node){
            postOrderTraverse(node->left);
            postOrderTraverse(node->right);
            postOrder.push_back(node->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postOrderTraverse(root);
        return postOrder;
    }
};