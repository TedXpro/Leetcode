class Solution {
public:
    int appendCharacters(string s, string t) {
        int first = 0, longest = 0;
        while(first < s.length() && longest < t.length()){
            if(s[first] == t[longest])
                longest++;
            first++;
        }
        return t.length() - longest;
    }
};