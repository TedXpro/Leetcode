class Solution {
    const static int MOD = 1e9 + 7;
    int rev(int num){
        int reverse = 0;
        while(num > 0){
            reverse = (reverse * 10) + (num % 10);
            num /= 10;
        }
        return reverse;
    }
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> sums;
        for(int num : nums)
            sums.push_back(num - rev(num));
        
        int ans = 0;
        unordered_map<int, int> numbers;
        for(int sum : sums){
            ans = (ans + numbers[sum]) % MOD;
            numbers[sum]++;
        }
        return ans;
    }
};