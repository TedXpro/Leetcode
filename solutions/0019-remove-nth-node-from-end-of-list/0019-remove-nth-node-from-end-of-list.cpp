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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalElements = 0;
        ListNode* nodeptr = head;
        while(nodeptr){
            totalElements++;
            nodeptr = nodeptr->next;
        }

        int position = totalElements - n;    
        if(position == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }else {
            nodeptr = head;
            ListNode* prevNode = nullptr;

            for(int i = 0; i < position; i++){
                prevNode = nodeptr;
                nodeptr = nodeptr->next;
            }

            ListNode* temp = nodeptr;
            prevNode->next = nodeptr->next;
            delete temp;
        }
        return head;
    }
};