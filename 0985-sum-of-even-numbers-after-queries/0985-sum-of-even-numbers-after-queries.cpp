class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for(int num : nums){
            if(num % 2 == 0)
                evenSum += num;
        }

        vector<int> answer(nums.size());
        for(int i = 0; i < queries.size(); i++){
            int index = queries[i][1];
            if(nums[index] % 2 == 0){
                evenSum -= nums[index];
                nums[index] += queries[i][0];

                if(nums[index] % 2 == 0)
                    evenSum += nums[index];
            }
            else {
                nums[index] +=queries[i][0];
                if(nums[index] % 2 == 0)
                    evenSum += nums[index];
            }
            answer[i] = evenSum;
        }
        return answer;
    }
};