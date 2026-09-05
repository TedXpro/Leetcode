class Solution {
    static bool compare(const pair<int, int>& a, const pair<int, int>& b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> memo;
        for(int num : nums){
            memo[num]++;
        }

        vector<pair<int, int>> arr(memo.begin(), memo.end());
        sort(arr.begin(), arr.end(), compare);
        vector<int> answer;
        for(const pair<int, int> curr : arr){
            for(int i = 0; i < curr.second; i++){
                answer.push_back(curr.first);
            }
        }
        return answer;
    }
};