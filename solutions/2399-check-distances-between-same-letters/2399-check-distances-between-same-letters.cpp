class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> memo;
        for(int i = 0; i < s.length(); i++){
            if(memo.find(s[i]) != memo.end()){
                int curr = s[i] - 'a';
                if(distance[curr] != (i - memo[s[i]] - 1)){
                    return false;
                }
            } else {
                memo[s[i]] = i;
            }
        }
        return true;
    }
};