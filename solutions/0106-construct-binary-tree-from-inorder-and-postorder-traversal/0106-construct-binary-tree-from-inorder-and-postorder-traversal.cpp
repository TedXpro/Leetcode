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
    TreeNode* dfsConstruct(vector<int>& inorder, vector<int>& postorder, int start, int end, int &index){
        TreeNode* currNode = new TreeNode(postorder[index]);
        cout << currNode->val << endl;
        int leftoff = end;
        for(int i = end; i >= start; i--){
            if(postorder[index] == inorder[i]){
                leftoff = i;
                break;
            }
        }

        if(leftoff == end){
            currNode->right = nullptr;
        } else {
            currNode->right = dfsConstruct(inorder, postorder, leftoff + 1, end, --index);
        }

        if(start == leftoff){
            currNode->left = nullptr;
        } else {
            currNode->left = dfsConstruct(inorder, postorder, start, leftoff - 1, --index);
        }

        return currNode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        return dfsConstruct(inorder, postorder, 0, inorder.size() - 1, index);
    }
};