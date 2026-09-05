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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<double> answer;
        while(!bfs.empty()){
            int size = bfs.size();
            double currAve = 0;
            for(int i = 0; i < size; i++){
                TreeNode* curr = bfs.front();
                bfs.pop();
                currAve += curr->val;
                if(curr->left){
                    bfs.push(curr->left);
                }
                if(curr->right){
                    bfs.push(curr->right);
                }
            }

            answer.push_back(currAve / size);
        }

        return answer;
    }
};