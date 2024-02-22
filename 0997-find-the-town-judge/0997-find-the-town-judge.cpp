class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1)
            return n;
        unordered_map<int, vector<int>> memo;
        vector<int> citizens(n, 0);
        for(vector<int>& tr : trust){
            citizens[tr[0] - 1] = -1;
            if(citizens[tr[1] - 1] != -1)
                citizens[tr[1] - 1] = 1;
            memo[tr[1]].push_back(tr[0]);
        }      

        for(int index = 0; index < n; index++){
            if(citizens[index] == 1 && memo.find(index + 1) != memo.end() && memo[index + 1].size() == n - 1)
                return index + 1;
        }
        return -1;
    }
};