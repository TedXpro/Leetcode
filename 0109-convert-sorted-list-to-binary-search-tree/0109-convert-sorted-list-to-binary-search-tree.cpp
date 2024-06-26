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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void addElements(TreeNode*& nodeptr, vector<int>& nums, int start, int end){
        if(start > end)
            return;

        int middle = (start + end) / 2;
        TreeNode* newNode = new TreeNode;
        newNode->val = nums[middle];
        nodeptr = newNode;

        addElements(nodeptr->left, nums, start, middle - 1);
        addElements(nodeptr->right, nums, middle + 1, end);
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> numbers;
        while(head){
            numbers.push_back(head->val);
            head = head->next;
        }

        TreeNode* root = nullptr;
        addElements(root, numbers, 0, numbers.size() - 1);
        return root;
    }
};