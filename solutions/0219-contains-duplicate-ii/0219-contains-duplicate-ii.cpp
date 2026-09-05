class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> memo;

        for(int i = 0; i < nums.size(); i++)
            memo[nums[i]].push_back(i);

        for(auto it : memo){
            if(it.second.size() > 1){
                for(int i = 1; i < it.second.size(); i++){
                    if(it.second[i] - it.second[i - 1] <= k)
                        return true;
                }
            }
        }
        return false;
    }
};