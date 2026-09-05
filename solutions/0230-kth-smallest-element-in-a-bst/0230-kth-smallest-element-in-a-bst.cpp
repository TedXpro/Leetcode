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
    void inorder(TreeNode* nodeptr, int& k, int& index, int &answer){
        if(nodeptr){
            inorder(nodeptr->left, k, index, answer);
            index++;

            if(index == k){
                answer = nodeptr->val;
                return;
            }
            inorder(nodeptr->right, k, index, answer);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int answer =  -1;
        int index = 0;
        inorder(root, k, index, answer);
        return answer;
    }
};