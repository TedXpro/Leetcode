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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        int answer = 1;
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = bfs.front();
                bfs.pop();
                if(!curr->left && !curr->right){
                    return answer;
                }
                if(curr->left){
                    bfs.push(curr->left);
                }
                if(curr->right){
                    bfs.push(curr->right);
                }
            }
            answer++;
        }
        return answer;
    }
};