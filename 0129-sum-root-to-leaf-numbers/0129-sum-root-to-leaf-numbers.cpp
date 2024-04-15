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
    void findSum(TreeNode* nodeptr, int prev, int &answer){
        if(nodeptr){
            prev += nodeptr->val;
            if(nodeptr->left == nullptr && nodeptr->right == nullptr){
                answer += prev;
                return;
            }
            prev *= 10;
            findSum(nodeptr->left, prev, answer);
            findSum(nodeptr->right, prev, answer);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int answer = 0;
        findSum(root, 0, answer);
        return answer;
    }
};