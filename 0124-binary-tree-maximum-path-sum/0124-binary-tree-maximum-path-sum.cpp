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
    int findPath(TreeNode* nodeptr, int &answer){
        if(nodeptr){
            int left = findPath(nodeptr->left, answer);
            int right = findPath(nodeptr->right, answer);
            left = max(left, 0);
            right = max(right, 0);
           
            answer = max(answer, nodeptr->val + left + right);

            return nodeptr->val + max(left, right);
        }

        return 0;
    }
public:
    int maxPathSum(TreeNode* root) {
        int answer = INT_MIN + 1;
        int num = findPath(root, answer);

        return answer;
    }
};