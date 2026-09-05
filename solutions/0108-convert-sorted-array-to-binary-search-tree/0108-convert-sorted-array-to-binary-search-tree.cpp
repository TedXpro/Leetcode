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
    void addElements(TreeNode*& nodeptr, vector<int>& nums, int start, int end){
        if(start > end)
            return;
    
        int middle = (start + end) / 2;
        TreeNode* newNode = new TreeNode;
        newNode->val = nums[middle];
        nodeptr = newNode;
        
        addElements(nodeptr->left, nums, start, middle - 1);
        addElements(nodeptr->right, nums, middle + 1, end);
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        
        addElements(root, nums, 0, nums.size() - 1);
        return root;
    }
};