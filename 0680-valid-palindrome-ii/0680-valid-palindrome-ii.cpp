class Solution {
    bool checkSubstring(string s){
        string rev = s;
        reverse(s.begin(), s.end());
        return rev == s;
    }
public:
    bool validPalindrome(string s) {
        for(int start = 0, end = s.length() - 1; start < end; start++, end--){
            if(s[start] != s[end]){
                if(checkSubstring(s.substr(start, end - start)))
                    return true;
                else if(checkSubstring(s.substr(start + 1, end - start)))
                    return true;
                else 
                    return false;
                
            }
        }
        return true;
    }
};