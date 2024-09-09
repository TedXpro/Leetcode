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
private:
    ListNode* getKth(ListNode* curr, int k){
        while(curr && k > 0){
            k--;
            curr = curr->next;
        }
        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* revHead = new ListNode(0, head);
        ListNode* groupPtr = revHead;
        
        while(true){
            ListNode* nodeptr = getKth(groupPtr, k);
            if(!nodeptr){
                break;
            }

            ListNode* nextGroup = nodeptr->next;
            ListNode* prev = nodeptr->next;
            ListNode* curr = groupPtr->next;
            while(curr != nextGroup){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPtr->next;
            groupPtr->next = nodeptr;
            groupPtr = temp;
        }

        return revHead->next;

    }
};