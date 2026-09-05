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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* nodeptr = head;
        int size = 0;
        while(nodeptr){
            size++;
            nodeptr = nodeptr->next;
        }
        cout << size << endl;
        int cal = size / k;
        cout << cal << endl;
        int rem = size % k;
        cout << rem << endl;
        nodeptr = head;
        vector<ListNode*> answer;
        while(nodeptr){
            ListNode* currHead = nullptr;
            ListNode* currptr = currHead;
            int currCal;
            // nodeptr = nodeptr->next;
            if(rem > 0){
                currHead = nodeptr ?  new ListNode(nodeptr->val) : nodeptr;
                currptr = currHead;
                nodeptr = nodeptr? nodeptr->next : nodeptr;
                currCal = cal;
                rem--;
            } else {
                currHead = nodeptr ?  new ListNode(nodeptr->val) : nodeptr;
                currptr = currHead;
                nodeptr = nodeptr? nodeptr->next : nodeptr;
                currCal = cal - 1;
            }
            
            
            while(currptr && currCal > 0){
                currptr->next = nodeptr ? new ListNode(nodeptr->val) : nodeptr;
                currptr = currptr->next;
                nodeptr = nodeptr ? nodeptr->next : nodeptr;
                currCal--;
            }
            
            if(!nodeptr){
                // currptr->next = nullptr;
            }
            answer.push_back(currHead);
        }
        while(answer.size() < k){
            answer.push_back(nullptr);
        }
        return answer;
    }
};