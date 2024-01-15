class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> winLose;

        for(vector<int> match : matches){
            winLose[match[0]];
            winLose[match[1]]++;
        }

        vector<vector<int>> answer(2, vector<int>());

        for(auto pair : winLose){
            if(pair.second == 0)
                answer[0].push_back(pair.first);
            else if(pair.second == 1)
                answer[1].push_back(pair.first);
        }
        return answer;
    }
};