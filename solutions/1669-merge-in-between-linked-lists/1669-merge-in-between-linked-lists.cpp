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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) { 
        ListNode* nodeptr1 = list1;
        for(int i = 0; i < a - 1; i++)
            nodeptr1 = nodeptr1->next;
            
        ListNode* end1 = nodeptr1->next;
        for(int i = a; i < b; i++)
            end1 = end1->next;
        
        ListNode* tempNode = nodeptr1->next;
        nodeptr1->next = list2;

        ListNode* nodeptr2 = list2;
        while(nodeptr2->next)
            nodeptr2 = nodeptr2->next;

        nodeptr2->next = end1->next;
        delete tempNode;
        return list1;
    }
};