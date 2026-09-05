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
private:
    void insertNode(TreeNode* nodeptr, int &val, int &depth, int currentDepth){
        if(nodeptr){
            if(currentDepth == depth){
                TreeNode* leftNode = new TreeNode();
                leftNode->val = val;
                leftNode->left = nodeptr->left;
                TreeNode* rightNode = new TreeNode();
                rightNode->val = val;
                rightNode->right = nodeptr->right;

                nodeptr->left = leftNode;
                nodeptr->right = rightNode;
                return;
            }
            insertNode(nodeptr->left, val, depth, currentDepth + 1);
            insertNode(nodeptr->right, val, depth, currentDepth + 1);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* nodeptr = new TreeNode();
            nodeptr->val = val;
            nodeptr->left = root;
            root = nodeptr;
            return root;
        }
        int d = depth - 1;
        insertNode(root, val, d, 1);
        return root;
    }
};