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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* nodeptr = head;
        ListNode* deletedNode = head;
        while(nodeptr->next){
            prevNode = deletedNode;
            deletedNode = deletedNode->next;

            if(nodeptr->next && nodeptr->next->next)
                nodeptr = nodeptr->next->next;
            else 
                nodeptr = nodeptr->next;
        }
        ListNode* temp = nullptr;
        if(prevNode){
            temp = deletedNode;
            prevNode->next = deletedNode->next;
            delete temp;
        }else {
            temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }
};