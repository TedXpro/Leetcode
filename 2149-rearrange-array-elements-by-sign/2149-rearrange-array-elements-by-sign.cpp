class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int> positives;
        // vector<int> negatives;
        // for(int num : nums)
        //     num < 0 ? negatives.push_back(num) : positives.push_back(num);
        
        // vector<int> answer;
        // for(int i = 0; i < negatives.size(); i++){
        //     answer.push_back(positives[i]);
        //     answer.push_back(negatives[i]);
        // }
        // return answer;
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