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
    void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>> &map){
        if(current == nullptr){
            return;
        }
        if(map.find(current->val) == map.end())
            map[current->val] = unordered_set<int>();
        unordered_set<int> &adjacencyList = map[current->val];
        if(parent != 0)
            adjacencyList.insert(parent);
        if(current->left != nullptr)
            adjacencyList.insert(current->left->val);
        if(current->right != nullptr)
            adjacencyList.insert(current->right->val);

        convert(current->left, current->val, map);
        convert(current->right, current->val, map); 
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> map;
        convert(root, 0, map);
        queue<int> q;
        q.push(start);
        int minuteCount = 0;
        unordered_set<int> visited;
        visited.insert(start);

        while(!q.empty()){
            int levelSize = q.size();
            while(levelSize > 0){
                int current = q.front();
                q.pop();

                for(int num : map[current]){
                    if(visited.find(num) == visited.end()){
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minuteCount++;
        }
        return minuteCount - 1;
    }
};