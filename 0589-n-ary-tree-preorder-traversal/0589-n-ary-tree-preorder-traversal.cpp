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
    void preOrderTraverse(Node* nodeptr, vector<int>& answer){
        if(nodeptr){
            answer.push_back(nodeptr->val);
            for(int i = 0; i < nodeptr->children.size(); i++){
                preOrderTraverse(nodeptr->children[i], answer);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> answer;
        preOrderTraverse(root, answer);
        return answer;
    }
};