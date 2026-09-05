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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        int currIndex = 1;
        int prevCritIndex = 0;
        int firstCritIndex = 0;

        while(currNode->next != nullptr){
            if((currNode->val < prevNode->val && currNode->val < currNode->next->val) || (currNode->val > prevNode->val && currNode->val > currNode->next->val)){
                if(prevCritIndex == 0){
                    prevCritIndex = currIndex;
                    firstCritIndex = currIndex;
                } else {
                    minDist = min(minDist, currIndex - prevCritIndex);
                    prevCritIndex = currIndex;
                }
            }

            currIndex++;
            prevNode = currNode;
            currNode = currNode->next;
        }
        if(minDist != INT_MAX){
            return vector<int>{minDist, prevCritIndex - firstCritIndex};
        }

        return vector<int>{-1,-1};
    }
};