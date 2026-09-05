class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0, count = 0;
        vector<int> rem(k);
        rem[0] = 1;
        for(int num : nums){
            prefix = (prefix + num % k + k) % k;
            count += rem[prefix];
            rem[prefix]++;
        }

        return count;
    }
};