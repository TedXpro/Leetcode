class Solution {
    void permutation(vector<int>& nums, vector<vector<int>> &answer, vector<int> curr, int size, unordered_set<int> &memo){
        if(size == nums.size()){
            answer.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(memo.find(i) != memo.end()){
                continue;
            }

            curr.push_back(nums[i]);
            memo.insert(i);
            permutation(nums, answer, curr, size + 1, memo);
            memo.erase(i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> curr;
        unordered_set<int> memo;
        int size = 0;
        for(int i = 0; i < nums.size(); i++){
            curr.push_back(nums[i]);
            memo.insert(i);
            permutation(nums, answer, curr, size + 1, memo);
            memo.erase(i);
            curr.pop_back();
        }
        
        return answer;
    }
};