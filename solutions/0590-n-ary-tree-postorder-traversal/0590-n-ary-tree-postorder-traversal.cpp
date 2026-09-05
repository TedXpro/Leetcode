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
    void postOrderTraverse(Node* nodeptr, vector<int>& answer){
        if(nodeptr){
            for(int i = 0; i < nodeptr->children.size(); i++){
                postOrderTraverse(nodeptr->children[i], answer);
            }

            answer.push_back(nodeptr->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> answer;
        postOrderTraverse(root, answer);
        return answer;
    }
};