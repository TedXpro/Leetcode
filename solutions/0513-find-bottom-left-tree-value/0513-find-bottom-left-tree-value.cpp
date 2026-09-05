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
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> order;

        order.push(root);
        int answer;
        while(!order.empty()){
            TreeNode *nodeptr = order.front();
            order.pop();
            answer = nodeptr->val;

            if(nodeptr->right)
                order.push(nodeptr->right);
            if(nodeptr->left)
                order.push(nodeptr->left);
        }

        return answer;
    }
};