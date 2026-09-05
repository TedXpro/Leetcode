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
    ListNode* middleNode(ListNode* head) {
        int totalNodes = 0;
        ListNode* nodeptr = head;
        while(nodeptr){
            totalNodes++;
            nodeptr = nodeptr->next;
        }

        int index = totalNodes / 2;
        nodeptr = head;
        for(int i = 0; i < index; i++)
            nodeptr = nodeptr->next;
        
        return nodeptr;
    }
};