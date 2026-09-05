class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flips = 0;
        vector<bool> flip(nums.size(), false);
        int current = 0;
        for(int i = 0; i < nums.size(); i++){
            if(flip[i])
                current ^= 1;

            if((nums[i] ^ current) == 0){
                flips++;
                current ^= 1;
                if(i + k > nums.size())
                    return -1;
                flip[i + k] = true;
            }
        }
        return flips;
    }
};