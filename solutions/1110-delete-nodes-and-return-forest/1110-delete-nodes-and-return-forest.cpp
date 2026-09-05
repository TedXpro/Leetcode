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
    void traverse(TreeNode*& nodeptr, unordered_set<int> &toBeDeleted, vector<TreeNode*> &answer, bool deleted){
        if(nodeptr){
            // check if its deleted
            if(toBeDeleted.find(nodeptr->val) != toBeDeleted.end()){ // it is supposed to be deleted
                deleted = true;
                traverse(nodeptr->left, toBeDeleted, answer, deleted);  // check left node
                traverse(nodeptr->right, toBeDeleted, answer, deleted);

                nodeptr = nullptr;
            }

            if(deleted && nodeptr != nullptr && toBeDeleted.find(nodeptr->val) == toBeDeleted.end()){
                answer.push_back(nodeptr);
                deleted = false;
            }

            if(nodeptr){
                traverse(nodeptr->left, toBeDeleted, answer, deleted);
                traverse(nodeptr->right, toBeDeleted, answer, deleted);
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toBeDeleted;
        for(int num : to_delete){
            toBeDeleted.insert(num);
        }

        vector<TreeNode*> answer;
        if(toBeDeleted.find(root->val) == toBeDeleted.end()){
            answer.push_back(root);
        }

        traverse(root, toBeDeleted, answer, false);

        return answer;
    }
};