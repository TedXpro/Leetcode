class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> occurence;
        int maxRow = 0;
        for(int num : nums){
            occurence[num]++;
            if(occurence[num] > maxRow)
                maxRow = occurence[num];
        }
        
        vector<vector<int>> answer(maxRow);
        // for(auto occ : occurence){
        //     for(int row = 0; row < occ.second; row++){
        //         answer[row].push_back(occ.first);
        //     }
        // }
        for(int row = 0; row < maxRow; row++){
            for(auto occ = occurence.begin(); occ != occurence.end(); ){
                answer[row].push_back(occ->first);
                occ->second--;
                if(occ->second == 0)
                    occ = occurence.erase(occ);
                else 
                    occ++;
                
            }
        }

        return answer;
    }
};