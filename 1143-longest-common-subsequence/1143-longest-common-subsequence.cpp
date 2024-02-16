class Solution {
private:
    int lcs(string &text1, int index1, string &text2, int index2, unordered_map<string, int> &memo){
        if(index1 >= text1.length() || index2 >= text2.length())
            return 0;
        string key = to_string(index1) + "," + to_string(index2);
        if(memo.find(key) != memo.end())
            return memo[key];
        
        if(text1[index1] == text2[index2]){
            memo[key] = 1 + lcs(text1, index1 + 1, text2, index2 + 1, memo);
            return memo[key];
        }
        memo[key] = max(lcs(text1, index1 + 1, text2, index2, memo), lcs(text1, index1, text2, index2 + 1, memo));
        return memo[key];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        unordered_map<string, int> memo;
        return lcs(text1, 0, text2, 0, memo);
    }
};