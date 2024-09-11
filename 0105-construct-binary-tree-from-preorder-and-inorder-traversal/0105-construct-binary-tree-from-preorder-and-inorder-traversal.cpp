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
    TreeNode* dfsConstruct(vector<int>& preorder, vector<int> currInorder, int& index){
        if(index >= preorder.size()){
            return nullptr;
        }
        TreeNode* currNode = new TreeNode(preorder[index]);
        vector<int> nums;
        int start = 0;
        for(int i = 0; i < currInorder.size(); i++){
            if(currInorder[i] == preorder[index]){
                start = i;
                break;
            }
            nums.push_back(currInorder[i]);
        }

        if(nums.size() == 0){
            currNode->left = nullptr;
        } else {
        
            currNode->left = dfsConstruct(preorder, nums, ++index);
        }

        nums.clear();
        for(int i = start + 1; i < currInorder.size(); i++){
            nums.push_back(currInorder[i]);
        }

         if(nums.size() == 0){
            currNode->right = nullptr;
        } else {
            currNode->right = dfsConstruct(preorder, nums, ++index);
        }

        return currNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return dfsConstruct(preorder, inorder, index);
    }
};