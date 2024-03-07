class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;
        int tIndex = 0;
        for(; tIndex < t.length(); tIndex++){
            if(sIndex < s.length()){
                if(s[sIndex] == t[tIndex])
                    sIndex++;
            }else 
                break;
            
        }
        
        return sIndex == s.length();
    }
};