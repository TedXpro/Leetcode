/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> memo;
        Node* curr = head;
        while(curr){
            Node* newNode = new Node(curr->val);
            memo[curr] = newNode;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            Node* currCopy = memo[curr];
            currCopy->next = memo[curr->next];
            currCopy->random = memo[curr->random];
            curr = curr->next;
        }

        return memo[head];
    }
};