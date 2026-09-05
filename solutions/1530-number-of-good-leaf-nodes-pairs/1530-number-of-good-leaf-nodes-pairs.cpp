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
    void traverse(TreeNode* nodeptr, unordered_map<TreeNode*, vector<TreeNode*>>& graph, unordered_set<TreeNode*> &leaves, TreeNode* prevNode){
        if(!nodeptr){
            return;
        }
        if(!nodeptr->left&& !nodeptr->right){
            leaves.insert(nodeptr);
        }
        if(prevNode){
            graph[prevNode].push_back(nodeptr);
            graph[nodeptr].push_back(prevNode);
        }

        traverse(nodeptr->left, graph, leaves, nodeptr);
        traverse(nodeptr->right, graph, leaves, nodeptr);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leaves;

        traverse(root, graph, leaves, nullptr);

        int count = 0;
        for(auto &leaf : leaves){
            queue<TreeNode*> queue;
            unordered_set<TreeNode*> visited;
            queue.push(leaf);
            visited.insert(leaf);

            for(int i = 0; i <= distance; i++){
                int size = queue.size();
                for(int j = 0; j < size; j++){
                    TreeNode* curr = queue.front();
                    queue.pop();
                    // if(leaves.find(curr) != leaves.end() && curr != leaf){
                    if (leaves.count(curr) && curr != leaf) {
                        count++;
                    }
                    // if(graph.find(curr) != graph.end()){
                    if (graph.count(curr)) {
                        for(auto neighbour : graph[curr]){
                            // if(visited.find(neighbour) == visited.end()){
                            if (!visited.count(neighbour)) {
                                queue.push(neighbour);
                                visited.insert(neighbour);
                            }
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};