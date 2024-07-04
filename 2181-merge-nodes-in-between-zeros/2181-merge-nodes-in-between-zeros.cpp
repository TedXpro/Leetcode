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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* answer = new ListNode(0, nullptr);
        ListNode* ansPtr = answer;
        int sum = 0;
        while(head != nullptr){
            if(head->val == 0){
                head = head->next;
                if(sum == 0){
                    continue;
                } 
                ListNode *newNode = new ListNode(sum, nullptr);
                ansPtr->next = newNode;
                ansPtr = ansPtr->next;
                sum = 0;
            }
            else {
                sum += head->val;
                head = head->next;
            }
        }

        return answer->next;
    }
};