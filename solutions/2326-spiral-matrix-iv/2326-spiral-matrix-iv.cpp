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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* nodeptr = head;
        vector<vector<int>> answer(m, vector<int>(n, -1));
        int row = 0, col = 0;
        int numRows = m, numCols = n;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int index = 0;
        answer[0][0] = nodeptr->val;
        nodeptr = nodeptr->next;
        while(nodeptr){
            int i = row + directions[index][0], j = col + directions[index][1];
            while(nodeptr && (i >= 0 && i < m) && (j >= 0 && j < n) && answer[i][j] == -1){
                answer[i][j] = nodeptr->val;
                i += directions[index][0];
                j += directions[index][1];
                nodeptr = nodeptr->next;
            }
            row = i - directions[index][0];
            col = j - directions[index][1];
            index = (index + 1) % 4;
        }

        return answer;
    }
};