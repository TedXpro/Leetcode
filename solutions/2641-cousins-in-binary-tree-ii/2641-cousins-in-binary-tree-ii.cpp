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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<int> levelSum;
        
        bfs.push(root);
        while(!bfs.empty()){
            int size = bfs.size();
            int currSum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* nodeptr = bfs.front();
                bfs.pop();
                currSum += nodeptr->val;
                if(nodeptr->left){
                    bfs.push(nodeptr->left);
                } 
                if(nodeptr->right){
                    bfs.push(nodeptr->right);
                }
            }

            levelSum.push_back(currSum);
        }

        bfs.push(root);
        root->val = 0;
        int index = 1;
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i = 0; i < size; i++){
                TreeNode* nodeptr = bfs.front();
                cout << nodeptr->val << endl;
                bfs.pop();

                int sub = nodeptr->left ? nodeptr->left->val : 0;
                sub += nodeptr->right ? nodeptr->right->val : 0;
                if(nodeptr->left){
                    nodeptr->left->val = levelSum[index] - sub;
                    bfs.push(nodeptr->left);
                }
                if(nodeptr->right){
                    nodeptr->right->val = levelSum[index] - sub;
                    bfs.push(nodeptr->right);
                }
            }
            index++;
        }   

        return root;
    }
};