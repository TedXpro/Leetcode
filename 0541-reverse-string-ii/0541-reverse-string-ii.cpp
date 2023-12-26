class Solution {
public:
    string reverseStr(string s, int k) {
        // string answer(s.length());
        for(int start = 0; start < s.length(); start += 2 * k){
            int i = start;
            int j = start + k - 1 <= s.length() - 1 ? start + k - 1 : s.length() - 1;
            while(i < j){
                swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};