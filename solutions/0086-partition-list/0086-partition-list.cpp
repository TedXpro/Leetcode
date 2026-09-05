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
    ListNode* partition(ListNode* head, int x) {
        ListNode* answer = new ListNode(0);
        ListNode* ansPtr = answer;
        ListNode* nodeptr = head;
        while(nodeptr){
            if(nodeptr->val < x){
                ansPtr->next = new ListNode(nodeptr->val, nullptr);
                ansPtr = ansPtr->next;
            }
            nodeptr = nodeptr->next;
        }

        nodeptr = head;
        while(nodeptr){
            if(nodeptr->val >= x){
                ansPtr->next = new ListNode(nodeptr->val, nullptr);
                ansPtr = ansPtr->next;
            }
            nodeptr = nodeptr->next;
        }

        return answer->next;
    }
};