class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> occurence;
        for(int num : nums)
            occurence[num]++;
        
        int count = 0;
        for(auto occ : occurence){
            if(occ.second == 1)
                return -1;
            else if(occ.second % 3 == 0)
                count += occ.second / 3;
            // else if(occ.second % 3 == 1)
            //     count += occ.second / 3 + 1;
            // else if(occ.second % 3 == 2){
            //     count += occ.second / 3 + 1;
            //     count += 1;
            // }   
            else
                count += occ.second / 3 + 1;
        }
        return count;
    }
};