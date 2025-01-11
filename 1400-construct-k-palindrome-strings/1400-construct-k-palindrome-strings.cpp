class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k){
            return false;
        }
        if(s.length() == k){
            return true;
        }

        unordered_map<char, int> memo;
        for(char ch : s){
            memo[ch]++;
        }

        int count = 0;
        for(auto m : memo){
            if(m.second % 2 == 1){
                count++;
            }
        }

        return count <= k;
    }
};