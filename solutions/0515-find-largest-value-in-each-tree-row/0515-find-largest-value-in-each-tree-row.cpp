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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> queue;
        queue.push(root);

        vector<int> answer;
        while(!queue.empty()){
            int size = queue.size();
            int maxVal = INT_MIN;
            for(int i = 0; i < size; i++){
                TreeNode* curr = queue.front();
                queue.pop();
                maxVal = max(maxVal, curr->val);
                
                if(curr->left){
                    queue.push(curr->left);
                }
                if(curr->right){
                    queue.push(curr->right);
                }
            }

            answer.push_back(maxVal);
        }

        return answer;
    }
};