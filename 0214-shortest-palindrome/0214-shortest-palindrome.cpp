class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        if(s == ""){
            return s;
        }

        int left = 0; 
        for(int right = length - 1; right >= 0; right--){
            if(s[right] == s[left]){
                left++;
            }
        }

        if(left == length){
            return s;
        }

        string revS = s.substr(left);
        reverse(revS.begin(), revS.end());

        return revS + shortestPalindrome(s.substr(0, left)) + s.substr(left);
    }
};