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
    int gcd(int num1, int num2){
        if(num1 % num2 == 0)
            return num2;
        return gcd(num2, num1 % num2);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next){
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        while(second){
            int num = gcd(first->val, second->val);
            ListNode* newNode = new ListNode(num, second);
            first->next = newNode;
            first = second;
            second = second->next;
        }
        return head;
    }
};