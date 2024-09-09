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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        head = temp;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr){
            if(curr->next && curr->val == curr->next->val){
                int val = curr->val;
                while(curr && curr->val == val){
                    curr = curr->next;
                }

                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head->next;

    }
};