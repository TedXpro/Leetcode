class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer(2,0);
        long res = 0;
        for(int num : nums)
            res ^= num;
        
        res &= -res;
        for(int num : nums){
            if(res & num)
                answer[0] ^= num;
            else 
                answer[1] ^= num;
        }

        return answer;
    }
};