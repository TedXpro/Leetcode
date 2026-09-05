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
    ListNode* swapNodes(ListNode* head, int k) {
        int start = k - 1; // making it zero indexed for the beggining
        int totalElements = 0;
        ListNode* nodeptr = head;
        int index = 0;
        ListNode * firstNode = nullptr;
        
        while(nodeptr){
            if(index == start)
                firstNode = nodeptr;
            index++;
            totalElements++;
            nodeptr = nodeptr->next;
        }

        int end = totalElements - k;

        
        nodeptr = head;
        for(int i = 0; i < end; i++)
            nodeptr = nodeptr->next;

        int temp = nodeptr->val;
        nodeptr->val = firstNode->val;
        firstNode->val =  temp;

        return head;
    }
};