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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* nodeptr = head;
        int pos = 1;
        bool begin = false;

        while(nodeptr){
            if(pos == left){
                ListNode* curr;
                if(pos == 1){
                    curr = nodeptr;
                    begin = true;
                } else {
                    curr = nodeptr->next;
                }
                ListNode* revHead = curr ? new ListNode(curr->val) : nullptr;
                pos++;
                curr = curr ? curr->next : curr;
                ListNode* end = revHead;
                while(curr && pos <= right){
                    ListNode* temp = new ListNode(curr->val);
                    temp->next = revHead;
                    revHead = temp;
                    curr = curr->next;
                    pos++;
                }   

                if(begin){
                    head = revHead;
                } else {
                    nodeptr->next = revHead;
                }
                if(end){
                    end->next = curr;
                }
                break;
            }
            if(pos + 1 < left){
                nodeptr = nodeptr->next;
            }
            pos++;
        }

        return head;
    }
};