class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int ones = 0;
        int zeros = 0;
        for(int num : nums){
            if(num == 1)
                ones++;
        }

        int prev = -1;
        vector<int> answer;
        int max = 0;
        for(int i = 0; i < nums.size() + 1; i++){
            if(prev == 1)
                ones--;
            else if(prev == 0)
                zeros++;
            if(max < ones + zeros){
                max = ones + zeros;
                answer.clear();
                answer.push_back(i);
            }
            else if(max == ones + zeros)
                answer.push_back(i);
            if(i < nums.size())
                prev = nums[i];
        }
//         if(prev == 1)
//             ones--;
//         else if(prev == 0)
//             zeros++;
        
//         if(max < ones + zeros){
//             answer.clear();
//             answer.push_back(nums.size());
//         }
//         else if(max == ones + zeros)
//             answer.push_back(nums.size());
        return answer;
    }
};