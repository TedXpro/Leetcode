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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(!root){
            return answer;
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        bool invert = false;
        while(!bfs.empty()){
            int size = bfs.size();
            vector<int> currLevel;
            for(int i = 0; i < size; i++){
                TreeNode* curr = bfs.front();
                currLevel.push_back(curr->val);
                bfs.pop();
              
                if(curr->left){
                    bfs.push(curr->left);
                }
                if(curr->right){
                    bfs.push(curr->right);
                }
            }
            if(invert){
                reverse(currLevel.begin(), currLevel.end());
            }
            answer.push_back(currLevel);
            invert = !invert;

        }
        return answer;
    }
};