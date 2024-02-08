class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, vector<int>> memo;
        for(int i = 0; i < nums.size(); i++){
            memo[nums[i]].push_back(i);
        }

        sort(nums.begin(), nums.end());
        vector<int> answer(nums.size(),0);
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); i++){
            if(seen.find(nums[i]) == seen.end()){
                for(int j = 0; j < memo[nums[i]].size(); j++){
                    int index = memo[nums[i]][j];
                    answer[index] = i;
                }
                seen.insert(nums[i]);
            }
        }
        return answer;
    }
};