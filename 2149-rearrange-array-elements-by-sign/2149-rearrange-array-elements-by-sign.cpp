class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answer(nums.size());
        int negatives = 1;
        int positives = 0;

        for(int num : nums){
            if(num > 0){
                answer[positives] = num;
                positives += 2;
            }
            else {
                answer[negatives] = num;
                negatives += 2;
            }
        }
        return answer;
    }
};