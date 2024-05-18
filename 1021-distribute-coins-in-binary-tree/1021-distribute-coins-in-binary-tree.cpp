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
    int dfs(TreeNode*nodeptr, int &moves){
        if(nodeptr){
            int leftCoins = dfs(nodeptr->left, moves);
            int rightCoins = dfs(nodeptr->right, moves);

            moves += abs(leftCoins) + abs(rightCoins);

            return nodeptr->val - 1 + leftCoins + rightCoins;
        }
        return 0;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        int val = dfs(root, moves);
        return moves;
    }
};