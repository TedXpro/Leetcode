class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
        for(int start = 0; start < nums.size(); start++){
            int num = nums[start];
            string str;
            int curr = nums[start];
            while(start + 1 < nums.size() && nums[start + 1] - 1 == curr){
                curr = nums[start + 1];
                start++;
            }

            if(num == curr)
                str += to_string(num);
            else 
                str += to_string(num) + "->" + to_string(curr);
            answer.push_back(str);
        }

        return answer;
    }
};