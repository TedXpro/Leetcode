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
    ListNode *addValue(int value)
    {
        ListNode *newNode = new ListNode;
        newNode->val = value;
        newNode->next = nullptr;
        return newNode;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer = new ListNode;
        ListNode *ansPtr = answer;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int val1 = (l1 == nullptr)? 0 : l1->val;
            int val2 = (l2 == nullptr)? 0 : l2->val;

            int ans = val1 + val2 + carry;
            ansPtr->next = addValue(ans % 10);
            ansPtr = ansPtr->next;            
            carry = ans / 10;
            l1 = l1 == nullptr? l1 : l1->next;
            l2 = l2 == nullptr? l2 : l2->next;
        }

        if (carry != 0)
        {
            ansPtr->next = addValue(carry);
            ansPtr = ansPtr->next;
        }

        ListNode *temp = answer;
        answer = answer->next;
        delete temp;

        return answer;        
    }
};