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
    TreeNode* findStartNode(TreeNode* nodeptr, int startValue){
        if(nodeptr == nullptr) return nullptr;

        if(nodeptr->val == startValue) return nodeptr;

        TreeNode* left = findStartNode(nodeptr->left, startValue);

        if(left != nullptr) return left;
        return findStartNode(nodeptr->right, startValue);
    }

    void populateMap(TreeNode* nodeptr, unordered_map<int, TreeNode*>& map){
        if(nodeptr == nullptr) return;

        if(nodeptr->left != nullptr){
            map[nodeptr->left->val] = nodeptr;
            populateMap(nodeptr->left, map);
        }

        if(nodeptr->right != nullptr){
            map[nodeptr->right->val] = nodeptr;
            populateMap(nodeptr->right, map);
        }
    }

    string backTrack(TreeNode* nodeptr, unordered_map<TreeNode*, pair<TreeNode*, string>> &path){
        string answer;

        while(path.count(nodeptr)){
            answer += path[nodeptr].second;
            nodeptr = path[nodeptr].first;
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }


public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int, TreeNode*> parentMap;
        TreeNode* startNode = findStartNode(root, startValue);

        populateMap(root, parentMap);

        queue<TreeNode*> queue;
        queue.push(startNode);
        unordered_set<TreeNode*> visited;
        visited.insert(startNode);
        unordered_map<TreeNode*, pair<TreeNode*, string>> path;

        while(!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();

            if(curr->val == destValue){
                return backTrack(curr, path);
            }

            if(parentMap.find(curr->val) != parentMap.end()){
                TreeNode* nodeptr = parentMap[curr->val];
                if(visited.find(nodeptr) == visited.end()){
                    queue.push(nodeptr);
                    path[nodeptr] = {curr, "U"};
                    visited.insert(nodeptr);
                }
            }

            if(curr->right != nullptr && visited.find(curr->right) == visited.end()){
                queue.push(curr->right);
                path[curr->right] = {curr, "R"};
                visited.insert(curr->right);
            }

            if(curr->left != nullptr && visited.find(curr->left) == visited.end()){
                queue.push(curr->left);
                path[curr->left] = {curr, "L"};
                visited.insert(curr->left);
            }
        }
        return "";
    }
};