class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        set<int> check;
        for(int i = 0; i < ranges.size(); i++){
            for(int j = ranges[i][0]; j <= ranges[i][1] && j <= right; j++){
                check.insert(j);
            }
        }

        for(int i = left; i <= right; i++){
            if(check.find(i) == check.end())
                return false;
        }
        return true;
    }
};