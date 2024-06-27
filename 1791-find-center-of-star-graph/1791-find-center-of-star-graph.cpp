class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> memo;
        for(vector<int> &edge : edges){
            memo[edge[0]].push_back(edge[1]);
            memo[edge[1]].push_back(edge[0]);
        }    

        int total = memo.size() - 1;
        int star;
        for(auto &m : memo){
            if(m.second.size() == total){
                star = m.first;
                break;
            }
        }
        return star;
    }
};