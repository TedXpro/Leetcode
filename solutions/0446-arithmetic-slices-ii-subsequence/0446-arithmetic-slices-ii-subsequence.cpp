class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<long long int, long long int> subCount;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                long long int diff = (long long int)nums[i] - (long long int)nums[j];
                long long int keyCurr = diff * 2000 + i;
                long long int keyPrev = diff * 2000 + j;

                subCount[keyCurr] += subCount[keyPrev] + 1;
            }
        }    

        long long int  total = 0;
        for(auto itr = subCount.begin(); itr != subCount.end(); itr++)
            total += itr->second;
        
        return (int)(total - (nums.size() * (nums.size() - 1)) / 2);
    }
};