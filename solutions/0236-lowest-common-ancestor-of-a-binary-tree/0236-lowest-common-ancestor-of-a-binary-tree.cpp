/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool findLca(TreeNode* nodeptr, TreeNode* p, TreeNode* q, TreeNode* &answer){
        if(nodeptr){
            bool curr = false;
            if(nodeptr->val == p->val || nodeptr->val == q->val){
                curr = true;
            }
            bool left = findLca(nodeptr->left, p, q, answer);
            bool right = findLca(nodeptr->right, p, q, answer);

            if(left && right){
                answer = nodeptr;
                return true;
            }
            if((left || right) && curr){
                answer = nodeptr;
                return true;
            }

            return (left || right) || curr;
        }

        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* answer = nullptr;
        findLca(root, p, q, answer);
        return answer;
    }
};