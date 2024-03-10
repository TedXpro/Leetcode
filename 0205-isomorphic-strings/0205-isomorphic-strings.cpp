class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;
        for(int i = 0; i < s.length(); i++){
            if(sToT.contains(s[i]) && sToT[s[i]] != t[i])
                return false;
            else if(tToS.contains(t[i]) && tToS[t[i]] != s[i])
                return false;
            else {
                sToT[s[i]] = t[i];
                tToS[t[i]] = s[i];
            }
        }
        return true;
    }
};