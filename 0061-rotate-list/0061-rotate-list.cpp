/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0){
            return head;
        }
        ListNode* nodeptr = head;
        int count = 1;

        while(nodeptr->next){
            nodeptr = nodeptr->next;
            count++;
        }
        nodeptr->next = head;
        nodeptr = head;

        int rot = k % count;    
        int pos = count - rot - 1;
        for(int i = 0; i < pos; i++){
            nodeptr = nodeptr->next;
        }
        head = nodeptr->next;
        nodeptr->next = nullptr;
        

        return head;

    }
};