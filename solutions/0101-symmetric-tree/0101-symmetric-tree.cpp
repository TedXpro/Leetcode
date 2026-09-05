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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> curr;
            for(int i = 0; i < size; i++){
                TreeNode* nodeptr = q.front();
                cout << "current " << nodeptr->val << endl;
                q.pop();

                if(nodeptr->left){
                    curr.push_back(nodeptr->left->val);
                    q.push(nodeptr->left);
                } else {
                    cout << nodeptr->val << " here " << endl;
                    curr.push_back(-200);
                }
                if(nodeptr->right){
                    curr.push_back(nodeptr->right->val);
                    q.push(nodeptr->right);
                } else {
                    curr.push_back(-200);
                }                
            }
            for(int left = 0, right = curr.size() - 1; left < right; left++, right--){
                if(curr[left] != curr[right]){
                    return false;
                }
            }
        }

        return true;
    }
};