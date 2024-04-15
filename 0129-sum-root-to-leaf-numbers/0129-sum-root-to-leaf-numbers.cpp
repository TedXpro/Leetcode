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
    int findSum(TreeNode* nodeptr, int prev){
        if(nodeptr){
            prev += nodeptr->val;
            if(nodeptr->left == nullptr && nodeptr->right == nullptr)
                return prev;

            prev *= 10;
            return findSum(nodeptr->left, prev) + findSum(nodeptr->right, prev);
        }
        return 0;
    }
public:
    int sumNumbers(TreeNode* root) {
        int answer = findSum(root, 0);
        return answer;
    }
};