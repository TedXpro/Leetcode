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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> child, parent;
        unordered_map<int, vector<pair<int, int>>> graph;
        for(vector<int>& desc : descriptions){
            int p = desc[0], c = desc[1], isLeft = desc[2];
            parent.insert(p);
            parent.insert(c);
            child.insert(c);
            graph[p].emplace_back(c, isLeft);
        }

        for(auto it = parent.begin(); it != parent.end();){
            if(child.find(*it) != child.end()){
                it = parent.erase(it);
            } else{
                ++it;
            }
        }

        TreeNode* head = new TreeNode(*parent.begin());

        queue<TreeNode*> queue;
        queue.push(head);
        while(!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();
            for(auto& c : graph[curr->val]){
                int val = c.first, isLeft = c.second;
                TreeNode* ch = new TreeNode(val);
                queue.push(ch);
                if(isLeft == 1){
                    curr->left = ch;
                } else{
                    curr->right = ch;
                }
            }
        }
        return head;
    }
};