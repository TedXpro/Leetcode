class Solution {

    void permute(vector<vector<int>>& answer, int &total, int size, unordered_map<int, int>& memo, vector<int> curr){
        if(size == total){
            answer.push_back(curr);
            return;
        }

        for(auto& m : memo){
            if(m.second == 0){
                continue;
            }
            curr.push_back(m.first);
            m.second--;
            permute(answer, total, size + 1, memo, curr);
            curr.pop_back();
            m.second++;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> memo;
        for(int num : nums){
            memo[num]++;
        }

        vector<vector<int>> answer;
        vector<int> curr;
        int total = nums.size(); 
        for(auto& m : memo){
            curr.push_back(m.first);
            m.second--;
            permute(answer, total, 1, memo, curr);
            curr.pop_back();
            m.second++;
        }

        return answer;
    }
};