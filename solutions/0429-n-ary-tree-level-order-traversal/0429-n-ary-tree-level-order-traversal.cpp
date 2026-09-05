/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> answer;
        if(!root){
            return answer;
        }
        queue<Node*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int size = bfs.size();
            vector<int> currLevel;
            for(int i = 0; i < size; i++){
                Node* curr = bfs.front();
                currLevel.push_back(curr->val);
                bfs.pop();
                for(int i = 0; i < curr->children.size(); i++){
                    bfs.push(curr->children[i]);
                }
            }
            answer.push_back(currLevel);
        }
        return answer;
    }
};