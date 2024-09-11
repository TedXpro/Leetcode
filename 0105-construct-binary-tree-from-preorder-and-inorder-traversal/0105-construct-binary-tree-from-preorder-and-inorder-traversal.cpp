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
    TreeNode* dfsConstruct(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index){
        if(index >= preorder.size()){
            return nullptr;
        }
        TreeNode* currNode = new TreeNode(preorder[index]);
        int leftoff = start;
        for(int i = start; i < end; i++){
            if(inorder[i] == preorder[index]){
                leftoff = i;
                break;
            }
        }

        if(leftoff - start == 0){
            currNode->left = nullptr;
        } else {
            currNode->left = dfsConstruct(preorder, inorder, start, leftoff, ++index);
        }

         if(end - (leftoff + 1) == 0){
            currNode->right = nullptr;
        } else {
            currNode->right = dfsConstruct(preorder, inorder, leftoff + 1, end, ++index);
        }

        return currNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return dfsConstruct(preorder, inorder, 0, inorder.size(), index);
    }
};