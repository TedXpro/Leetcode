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
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        stack<ListNode*> st;
        int counter = 0;
        ListNode* nodeptr = head;
        
        while (nodeptr) {
            st.push(nodeptr);
            nodeptr = nodeptr->next;
            counter++;
        }
        nodeptr = head;
        int mid = counter / 2;
        
        for (int i = 0; i < mid; i++) {
            ListNode* currNode = st.top();
            st.pop();
            currNode->next = nodeptr->next;
            nodeptr->next = currNode;
            nodeptr = currNode->next;
        }
        
        nodeptr->next = nullptr;
    }
};