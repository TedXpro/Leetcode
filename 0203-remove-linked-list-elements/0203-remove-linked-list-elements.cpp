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
class Solution{
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return nullptr;

        while (head && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        ListNode* nodeptr = head;
        ListNode* previous = nullptr;

        while (nodeptr) {
            if (nodeptr->val == val) {
                if (previous)
                    previous->next = nodeptr->next;

                ListNode* temp = nodeptr;
                nodeptr = nodeptr->next;
                delete temp;
            } else {
                previous = nodeptr;
                nodeptr = nodeptr->next;
            }
        }

        return head;
    }
};