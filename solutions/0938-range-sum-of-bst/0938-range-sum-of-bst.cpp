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
    void search(TreeNode* nodeptr, int low, int high, int &answer){
        if(nodeptr){
            if(nodeptr->val <= high && nodeptr->val >= low)
                answer += nodeptr->val;
            search(nodeptr->left, low, high, answer);
            search(nodeptr->right, low, high, answer);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int answer = 0;
        search(root, low, high, answer);
        return answer;
    }
};