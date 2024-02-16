/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        /* O(n) Solution */
        // ListNode* nextNode = node->next;
        // while(nextNode->next != nullptr){
        //     node->val = nextNode->val;
        //     nextNode = nextNode->next;
        //     node = node->next;
        // }
        // node->val = nextNode->val;
        // node->next = nullptr;
        // delete nextNode;

        /* O(1) Solution */
        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};