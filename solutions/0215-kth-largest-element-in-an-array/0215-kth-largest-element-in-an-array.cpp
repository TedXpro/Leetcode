class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue;
        for(int num : nums){
            if(queue.size() == k){
                if(queue.top() < num){
                    queue.pop();
                    queue.push(num);
                }
            } else {
                queue.push(num);
            }
        }

        return queue.top();
    }
};