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
class BSTIterator {
    vector<int> inorder;
    int index;
public:
    BSTIterator(TreeNode* root) {
        index = 0;
        inorderTraverse(root);
    }

    void inorderTraverse(TreeNode* nodeptr){
        if(nodeptr){
            inorderTraverse(nodeptr->left);
            inorder.push_back(nodeptr->val);
            inorderTraverse(nodeptr->right);
        }
    }
    
    int next() {
        return inorder[index++];
    }
    
    bool hasNext() {
        if(index < inorder.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */