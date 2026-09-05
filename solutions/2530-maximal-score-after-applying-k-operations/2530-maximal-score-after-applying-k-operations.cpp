class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for(int num : nums){
            heap.push(num);
        }

        long long count = 0;
        while(k > 0){
            double curr = heap.top();
            heap.pop();

            count += curr; 
            heap.push(ceil(curr / 3));
            k--;
        }

        return count;
    }
};