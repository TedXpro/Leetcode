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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* nodeptr = new ListNode();
        nodeptr->val = 0;
        nodeptr->next = head;
        ListNode* start = nodeptr;

        while(start){
            ListNode* end = start->next;
            int sum = 0;
            while(end){
                sum += end->val;

                if(sum == 0)
                    start->next = end->next;
                end = end->next;
            }

            start = start->next;
        }
        return nodeptr->next;
    }
};