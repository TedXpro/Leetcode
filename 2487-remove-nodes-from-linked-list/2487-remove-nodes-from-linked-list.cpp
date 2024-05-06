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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* current = head;

        while(current){
            stack.push(current);
            current = current->next;
        }

        current = stack.top();
        stack.pop();
        int maxi = current->val;
        ListNode* answer = new ListNode(maxi);

        while(!stack.empty()){
            current = stack.top();
            stack.pop();
            if(current->val < maxi)
                continue;
            ListNode* newNode = new ListNode(current->val);
            newNode->next = answer;
            answer = newNode;
            maxi = current->val;
        }
        return answer;
    }
    
};