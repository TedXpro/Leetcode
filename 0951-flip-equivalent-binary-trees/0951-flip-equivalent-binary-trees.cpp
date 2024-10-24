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
    bool traverse(TreeNode* nodeptr1, TreeNode* nodeptr2){
        if(nodeptr1 == nullptr && nodeptr2 == nullptr){
            return true;
        }

        if(nodeptr1 == nullptr || nodeptr2 == nullptr){
            return false;
        }

        if(nodeptr1->val != nodeptr2->val){
            return false;
        }

        bool curr1 = traverse(nodeptr1->left, nodeptr2->left) && traverse(nodeptr1->right, nodeptr2->right);
        bool curr2 = traverse(nodeptr1->left, nodeptr2->right) && traverse(nodeptr1->right, nodeptr2->left);

        return curr1 || curr2;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return traverse(root1, root2);
    }
};