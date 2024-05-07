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
    ListNode* doubleIt(ListNode* head) {
        long long number = 0;
        while(head){
            number = number * 10 + head->val;
            head = head->next;
        }

        number *= 2;
        ListNode* answer = new ListNode(number % 10);
        number /= 10;
        while(number > 0) {
            ListNode * newNode = new ListNode(number % 10);
            number /= 10;
            newNode->next = answer;
            answer = newNode;
        }
        return answer;
    }
};