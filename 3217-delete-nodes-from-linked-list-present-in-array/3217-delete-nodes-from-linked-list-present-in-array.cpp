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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> memo(nums.begin(), nums.end());
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != nullptr){
            if(memo.find(curr->val) != memo.end()){
                ListNode *next = curr->next;
                while(next != nullptr && memo.find(next->val) != memo.end()){
                    next = next->next;
                }
                prev->next = next;
                curr = next;
            }
            curr = curr != nullptr ? curr->next : nullptr;
            prev = prev != nullptr ? prev->next : prev;
        }

        if(memo.find(head->val) != memo.end()){
            return head->next;
        }

        return head;
    }
};