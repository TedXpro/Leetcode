class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> occurence;
        for(string word : words){
            for(char ch : word){
                occurence[ch]++;
            }
        }

        for(auto occ : occurence){
            if(occ.second % words.size() != 0)
                return false;
        }
        return true;
    }
};