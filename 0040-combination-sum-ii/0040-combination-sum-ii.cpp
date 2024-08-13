class Solution {
    void backTrack(vector<int>& candidates, vector<vector<int>>& answer, int target, vector<int> &curr, int index){
        if(target == 0){
            answer.push_back(curr);
            return;
        }

        for(int i = index; i < candidates.size() && candidates[i] <= target; i++){
            if(i == index || candidates[i] != candidates[i - 1]){
                curr.push_back(candidates[i]);
                backTrack(candidates, answer, target - candidates[i], curr, i + 1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> curr;
        backTrack(candidates, answer, target, curr, 0);
        return answer;
    }
};