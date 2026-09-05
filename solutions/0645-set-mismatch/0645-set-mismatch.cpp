class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        vector<int> answer(2,0);
        for(int num : nums){
            memo[num - 1]++;
            if(memo[num - 1] == 2)
                answer[0] = num;
        }

        for(int i = 0; i < memo.size(); i++){
            if(memo[i] == 0){
                answer[1] = i + 1;
                break;
            }
        }
        return answer;
    }
};