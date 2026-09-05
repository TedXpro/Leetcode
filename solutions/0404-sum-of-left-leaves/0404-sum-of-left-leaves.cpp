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
    void dfs(TreeNode* nodeptr, int &answer){
        if(nodeptr){    
            if(nodeptr->left && nodeptr->left->left == nullptr && nodeptr->left->right == nullptr)
                answer += nodeptr->left->val;
            dfs(nodeptr->left, answer);
            dfs(nodeptr->right, answer);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }
};