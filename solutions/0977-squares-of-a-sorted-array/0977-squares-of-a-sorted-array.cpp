class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        vector<int> answer(nums.size());
        int index = nums.size() - 1;
        for(; start <= end; ){
            if(pow(nums[start], 2) > pow(nums[end], 2)){
                answer[index] = pow(nums[start], 2);
                start++;
            } else{
                answer[index] = pow(nums[end], 2);
                end--;
            }
            index--;
        }

        return answer;
    }
};