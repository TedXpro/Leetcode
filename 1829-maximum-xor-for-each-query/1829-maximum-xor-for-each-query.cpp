class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorPro = 0;
        for(int i = 0; i < nums.size(); i++){
            xorPro ^= nums[i];
        }

        vector<int> answer;
        int mask = (1 << maximumBit) - 1;
        for(int i = 0; i < nums.size(); i++){
            answer.push_back(xorPro ^ mask);
            xorPro ^= (nums[nums.size() - 1 - i]);
        }

        return answer;
    }
};