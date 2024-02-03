class Solution {
    int maxSum(vector<int> &arr, int k, vector<int> &dp, int start, int &size){
        
        if(start >= size)
            return 0;
        if(dp[start] != -1)
            return dp[start];
        
        int currMax = 0, sum = 0;
        int end = min(size, start + k);
        for(int i = start; i < end; i++){
            currMax = max(currMax, arr[i]);

            sum = max(sum, currMax * (i - start + 1) + maxSum(arr, k, dp, i + 1, size)); 
        }

        return dp[start] = sum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int size = arr.size();
        vector<int> dp(size, -1);

        return maxSum(arr, k, dp, 0, size);
    }
};