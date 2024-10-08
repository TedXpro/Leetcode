/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& memo){
        if(memo.find(node) != memo.end()){
            return memo[node];
        }

        Node* copy = new Node(node->val);
        memo[node] = copy;
        for(Node*& nei : node->neighbors){
            copy->neighbors.push_back(dfs(nei, memo));
        }

        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> memo;
        return dfs(node, memo);
    }
};