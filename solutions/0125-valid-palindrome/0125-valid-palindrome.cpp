class Solution {
public:
    bool isPalindrome(string s) { // optimal way have time complexity of O(n) and space comp of O(1)
        int start = 0; int end = s.length() - 1;
        for(; start < end; start++, end--){
            while(!isalnum(s[start]) && start < end)
                start++;
            while(!isalnum(s[end]) && end > start)
                end--;
            if(tolower(s[start]) != tolower(s[end]))
                return false;
        }
        return true;
    }
};

/* time complexity: O(n)
    space complexity: O(n) */
/* class Solution {
    vector<char> convertToArray(string &s){
        vector<char> str;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'){
                str.push_back(tolower(s[i]));
            }
        }
        return str;
    }
public:
    bool isPalindrome(string s) {
        vector<char> str = convertToArray(s);
        if(str.empty())
            return true;

        for(int start = 0, end = str.size() - 1; start < end; start++, end--){
            if(str[start] != str[end])
                return false;
        }

        return true;
    }
}; */