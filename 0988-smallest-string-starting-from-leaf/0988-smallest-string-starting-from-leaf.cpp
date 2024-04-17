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
    void findSmallest(TreeNode* nodeptr, string& s, string& answer){
        if(nodeptr){
            // s += static_cast<char>(nodeptr->val + 97);
            s.push_back(nodeptr->val + 'a');
            if(nodeptr->left == nullptr && nodeptr->right == nullptr){
                string res = s;
                reverse(res.begin(), res.end());
                answer = answer.empty() || res < answer ? res : answer;
            } else {
                findSmallest(nodeptr->left, s, answer);
                findSmallest(nodeptr->right, s, answer);
            }
            s.pop_back();
            return;
        }
        return;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string s = "", answer = "";
        findSmallest(root, s, answer);
        return answer;
    }
};