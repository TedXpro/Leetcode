class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = *max_element(nums.begin(), nums.end());
        int currMax = 1, currMin = 1;
        for(int n: nums){
            if(n == 0) {
                currMax = 1;
                currMin = 1;
            }

            int tmp = currMax * n;
            currMax = max({currMax * n, currMin * n, n});
            currMin = min({tmp, currMin * n, n});

            maximum = max({currMax, currMin, maximum});
        }
        
        return maximum;
    }
};