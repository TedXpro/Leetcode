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
    void preorder(TreeNode*& nodeptr){
        if(nodeptr){
            TreeNode* temp = nodeptr->right;
            if(nodeptr->left){
                TreeNode* curr = nodeptr->left;
                nodeptr->right = curr;
                nodeptr->left = nullptr;

                TreeNode* ptr = nodeptr->right;
                while(ptr->right){
                    ptr = ptr->right;
                }

                ptr->right = temp;                
            } 
            preorder(nodeptr->right);    
        }
    }
public:
    void flatten(TreeNode* root) {
        preorder(root);
    }
};