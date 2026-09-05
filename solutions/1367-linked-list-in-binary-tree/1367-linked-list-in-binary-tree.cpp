/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* nodeptr, TreeNode* tree){
        if(!nodeptr){
            return true;
        }
        if(!tree){
            return false;
        }

        bool answer = false;
        if(nodeptr->val == tree->val){
            answer |= dfs(nodeptr->next, tree->left);
            answer |= dfs(nodeptr->next, tree->right);
        }

        return answer;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }

        bool answer = dfs(head, root);

        answer |= isSubPath(head, root->left);
        answer |= isSubPath(head, root->right);

        return answer;
    }
};