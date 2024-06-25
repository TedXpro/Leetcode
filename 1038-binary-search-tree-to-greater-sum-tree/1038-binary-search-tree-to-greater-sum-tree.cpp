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
    void traverse(TreeNode* node, int &curr){
        if(node){
            traverse(node->right, curr);
            node->val = node->val + curr;
            curr = node->val;
            traverse(node->left, curr);
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int curr = 0;
        traverse(root, curr);
        return root;
    }
};