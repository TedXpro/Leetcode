class Solution {
private:
    void updateBitCounts(vector<int>& bitCounts, int number, int delta){
        for(int pos = 0; pos < 32; pos++){
            if((number >> pos) & 1){
                bitCounts[pos] += delta;
            }
        }
    }

    int convertBitCountsToNumber(const vector<int>& bitCounts){
        int res = 0;
        for(int pos = 0; pos < 32; pos++){
            if(bitCounts[pos] != 0){
                res |= 1 << pos;
            }
        }

        return res;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int answer = INT_MAX;
        int start = 0, end = 0;
        vector<int> bitCounts(32, 0);

        while(end < nums.size()){
            updateBitCounts(bitCounts, nums[end], 1);
            while(start <= end && convertBitCountsToNumber(bitCounts) >= k){
                answer = min(answer, end - start + 1);

                updateBitCounts(bitCounts, nums[start], -1);
                start++;
            }
            end++;
        }

        return answer == INT_MAX ? -1 : answer;
    }
};