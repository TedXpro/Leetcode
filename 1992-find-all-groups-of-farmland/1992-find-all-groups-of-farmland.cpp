class Solution {
public:
    void findEdges(vector<vector<int>>& land, int row, int col, vector<int> &ans, unordered_set<string> &memo) {
        if(row >= land.size() || col >= land[0].size() || land[row][col] == 0)
            return ;

        string key = to_string(row) + "," + to_string(col);
        cout << key << endl;
        if (memo.find(key) != memo.end()) 
            return ;
        memo.insert(key);

        if(row + 1 >= land.size() && col + 1 >= land[0].size()){
            // memo.insert(key);
            ans.push_back(row);
            ans.push_back(col);
            return ;
        }
        if(row + 1 < land.size() && col + 1 < land[0].size() && land[row + 1][col] == 0 && land[row][col + 1] == 0){
            // memo.insert(key);
            ans.push_back(row);
            ans.push_back(col);
            return ;
        }
        if(row + 1 >= land.size() && col + 1 < land[0].size() && land[row][col + 1] == 0){
            // memo.insert(key);
            ans.push_back(row);
            ans.push_back(col);
            return ;
        }
        if(col + 1 >= land[0].size() && row + 1 < land.size() && land[row + 1][col] == 0){
            // memo.insert(key);
            ans.push_back(row);
            ans.push_back(col);
            return ;
        }

        // bool status = 
        findEdges(land, row, col + 1, ans, memo); 
        // if (!status) 
            // status =
             findEdges(land, row + 1, col, ans, memo);
        // return status;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> answer;
        unordered_set<string> memo;
        for(int row = 0; row < land.size(); row++){
            for(int col = 0; col < land[0].size(); col++){
                if(land[row][col] == 1 && memo.find( to_string(row) + "," + to_string(col)) == memo.end()){
                    vector<int> ans;
                    ans.push_back(row);
                    ans.push_back(col);
                    // bool stat =
                     findEdges(land, row, col, ans, memo);
                    answer.push_back(ans);
                }
                    
            }
        }
        return answer;
    }
};