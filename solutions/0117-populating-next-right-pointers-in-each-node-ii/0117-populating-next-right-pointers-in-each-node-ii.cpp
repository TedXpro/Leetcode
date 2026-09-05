/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size - 1; i++){
                Node* curr = q.front(); 
                q.pop();
                Node* next = q.front();
                curr->next = next;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

            Node* curr = q.front();
            if(curr)
                curr->next = nullptr;
            q.pop();
            
            if(curr && curr->left){
                q.push(curr->left);
            }
            if(curr && curr->right){
                q.push(curr->right);
            }
        }
        return root;
    }
};