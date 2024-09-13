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
    TreeNode* findLca(TreeNode* nodeptr, TreeNode* p, TreeNode* q){
        if(nodeptr){
            if(nodeptr->val == p->val){
                return p;
            }
            if(nodeptr->val == q->val){
                return q;
            }

            if(nodeptr->val > p->val && nodeptr->val < q->val){
                return nodeptr;
            }

            if(nodeptr->val < p->val && nodeptr->val > q->val){
                return nodeptr;
            }
            TreeNode* left = findLca(nodeptr->left, p, q);
            TreeNode* right = findLca(nodeptr->right, p, q);

            return left ? left : right;
        }

        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLca(root, p, q);
    }
};