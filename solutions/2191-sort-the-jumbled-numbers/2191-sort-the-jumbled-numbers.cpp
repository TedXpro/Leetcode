class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> memo;
        for(int index = 0; index < nums.size(); index++){
            string curr = to_string(nums[index]);
            string changed = "";
            for(int i = 0; i < curr.length(); i++){
                changed += to_string(mapping[curr[i] - '0']);
            }
            memo.push_back({stoi(changed), index});

        }

        sort(memo.begin(), memo.end());
        vector<int> answer;
        for(pair<int, int> &curr : memo){
            answer.push_back(nums[curr.second]);
        }
        return answer;
    }
};