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

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* mergedList = new ListNode(0);
        ListNode* nodeptr = mergedList;
        while(left && right){
            if(left->val < right->val){
                nodeptr->next = left;
                left = left->next;
            } else {
                nodeptr->next = right;
                right = right->next;
            }
            nodeptr = nodeptr->next;
        }

        if(left){
            nodeptr->next = left;
        }

        if(right){
            nodeptr->next = right;
        }

        return mergedList->next;
    }

    ListNode* getMid(ListNode* nodeptr){
        ListNode* slow = nodeptr;
        ListNode* fast = nodeptr->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeSort(ListNode* nodeptr){
        if(!nodeptr || !nodeptr->next){
            return nodeptr;
        }     

        ListNode* left = nodeptr;
        ListNode* right = getMid(nodeptr);
        ListNode* temp = right->next;
        right->next = nullptr;
        right = temp;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }

public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};