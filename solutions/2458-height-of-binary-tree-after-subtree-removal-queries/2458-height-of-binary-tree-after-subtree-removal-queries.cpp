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
private:
    int maxHeights [100001];
    int currMaxHeight = 0;

    void preorderLR(TreeNode* nodeptr, int currHeight){
        if(nodeptr == nullptr){
            return;
        }

        maxHeights[nodeptr->val] = currMaxHeight;
        currMaxHeight = max(currMaxHeight, currHeight);

        preorderLR(nodeptr->left, currHeight + 1);
        preorderLR(nodeptr->right, currHeight + 1);
    }

    void preorderRL(TreeNode* nodeptr, int currHeight){
        if(nodeptr == nullptr){
            return;
        }

        maxHeights[nodeptr->val] = max(maxHeights[nodeptr->val], currMaxHeight);
        currMaxHeight = max(currMaxHeight, currHeight);

        preorderRL(nodeptr->right, currHeight + 1);
        preorderRL(nodeptr->left, currHeight + 1);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        preorderLR(root, 0);
        currMaxHeight = 0;
        preorderRL(root, 0);

        vector<int> answer;
        for(int query : queries){
            answer.push_back(maxHeights[query]);
        }

        return answer;
    }
};