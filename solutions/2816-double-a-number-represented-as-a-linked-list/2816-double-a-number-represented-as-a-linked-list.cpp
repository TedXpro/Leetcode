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
        stack<int> number;
        while(head){
            number.push(head->val);
            head = head->next;
        }

        ListNode* answer = new ListNode((number.top() * 2) % 10);
        int rem = number.top() * 2 / 10;
        number.pop();
        while(!number.empty()) {
            int curr = rem + number.top() * 2;
            number.pop();
            rem = curr / 10;
            ListNode * newNode = new ListNode(curr % 10);
            
            newNode->next = answer;
            answer = newNode;
        }
        if(rem != 0){
            ListNode* newNode = new ListNode(rem);
            newNode->next = answer;
            answer = newNode;
        }
        return answer;
    }
};