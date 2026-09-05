class Solution {
public:
    string longestPalindrome(string s) {
        string pali = "";
        int paliLen = 0;
        for(int i = 0; i < s.length(); i++){
            for(int start = i, end = i; end < s.length() && start >= 0; start--, end++){
                if(s[start] == s[end]){
                    int len = end - start + 1;
                    if(len > paliLen){
                        pali = s.substr(start, len);
                        paliLen = len;
                    }
                }
                else
                    break;
            }

            for(int start = i, end = i + 1; start >= 0 && end < s.length(); start--, end++){
                if(s[start] == s[end]){
                    int len = end - start + 1;
                    if(len > paliLen){
                        pali = s.substr(start, len);
                        paliLen = len;
                    }
                }
                else
                    break;
            }
        }
        return pali;
    }
};