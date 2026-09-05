class Solution {
public:
    int minimumLength(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end && s[start] == s[end]){
            int i = start + 1;
            while(i < end && s[start] == s[i])
                i++;
            
            i--;
            start = i;
            i = end - 1;
            while(i > start && s[end] == s[i])
                i--;
            i++;
            end = i;
            start++;
            end--;
        }

        return end - start + 1;
    }
};