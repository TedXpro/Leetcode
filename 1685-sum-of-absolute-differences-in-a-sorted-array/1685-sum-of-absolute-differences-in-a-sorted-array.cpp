class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            sum[i] = nums[i] + sum[i - 1];
        
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            int leftSum = sum[i] - nums[i];
            int rightSum = sum[sum.size() - 1] - sum[i];

            int leftCount = i;
            int rightCount = nums.size() - 1 - i;

            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];

            answer.push_back(leftTotal + rightTotal);
        }
        return answer;
    }
};