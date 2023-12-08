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
    string answer;
    void preOrderTraversal(TreeNode * node){
        if(node){
            answer += "(";
            answer += to_string(node->val);

            if(!node->left && node->right)
                answer += "()";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
            answer += ")";
        }
    }
    
public:
    string tree2str(TreeNode* root) {
        preOrderTraversal(root);
        return answer.substr(1,answer.length() - 2);
    }
};