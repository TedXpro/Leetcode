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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> answer;
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i = 0; i < size - 1; i++){
                TreeNode* curr = bfs.front();
                bfs.pop();
                if(curr->left){
                    bfs.push(curr->left);
                }
                if(curr->right){
                    bfs.push(curr->right);
                }
            }

            TreeNode* last = bfs.front();
            bfs.pop();
            if(last)
            answer.push_back(last->val);
            if(last && last->left){
                bfs.push(last->left);
            }
            if(last && last->right){
                bfs.push(last->right);
            }
        }

        return answer;
    }
};