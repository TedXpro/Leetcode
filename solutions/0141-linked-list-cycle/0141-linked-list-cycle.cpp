/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while(ptr1 && ptr1){
            if(ptr1 == ptr2)
                return true;
            
            ptr1 = ptr1->next;
            if(ptr2->next && ptr2->next->next)
                ptr2 = ptr2->next->next;
            else 
                return false;
        }

        return false;

    }
};