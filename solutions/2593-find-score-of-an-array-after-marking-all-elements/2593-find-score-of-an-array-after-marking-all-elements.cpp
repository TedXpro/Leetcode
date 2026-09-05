class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> numPairs(nums.size());
        for(int i = 0; i < nums.size(); i++){
            numPairs[i] = make_pair(nums[i], i);
        }

        sort(numPairs.begin(), numPairs.end());
        vector<bool> visited(nums.size(), false);
        long long answer = 0;
        for(int i = 0; i < nums.size(); i++){
            int number = numPairs[i].first;
            int index = numPairs[i].second;
            if(!visited[index]){
                answer += number;
                visited[index] = true;
                if(index - 1 >= 0){
                    visited[index - 1] = true; 
                }
                if(index + 1 < nums.size()){
                    visited[index + 1] = true;
                }
            }
        }

        return answer;
    }
};