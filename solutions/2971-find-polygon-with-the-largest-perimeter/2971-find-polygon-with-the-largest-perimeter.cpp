class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        priority_queue<int> heapQueue(nums.begin(), nums.end());
        long long maxPerimeter = 0;
        for(int num : nums)
            maxPerimeter += num;
        
        while(heapQueue.size() > 2){
            int num = heapQueue.top();
            if(maxPerimeter - num > num)
                return maxPerimeter;
            
            maxPerimeter -= num;
            heapQueue.pop();
        }

        return -1;
    }
};