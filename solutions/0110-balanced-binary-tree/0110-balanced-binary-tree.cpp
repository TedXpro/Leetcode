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
    int checkBalanced(TreeNode *nodeptr){
        if(nodeptr == nullptr)
            return -1;
        int leftTree = checkBalanced(nodeptr->left);
        if(leftTree == INT_MIN + 1)
            return INT_MIN + 1;
        int rightTree = checkBalanced(nodeptr->right);
        if(rightTree == INT_MIN + 1)
            return INT_MIN + 1;

        if(abs(leftTree - rightTree) > 1)
            return INT_MIN + 1;
        return max(rightTree, leftTree) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int num = checkBalanced(root);
        cout << num << endl;
        return num != INT_MIN + 1;
    }
};