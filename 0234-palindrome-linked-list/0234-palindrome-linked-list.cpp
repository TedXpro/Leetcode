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
    ListNode* reverse(ListNode* head){
        ListNode* reverseHead = nullptr;
        ListNode* nodeptr = head;

        while(nodeptr){
            ListNode* newNode = new ListNode;
            newNode->val = nodeptr->val;
            newNode->next = reverseHead;
            reverseHead = newNode;

            nodeptr = nodeptr->next;
        }

        return reverseHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* reverseHead = reverse(head);

        ListNode* headptr = head;
        ListNode* reverseptr = reverseHead;

        while(headptr){
            if(headptr->val != reverseptr->val)
                return false;
            headptr = headptr->next;
            reverseptr = reverseptr->next;
        }
        return true;
    }
};