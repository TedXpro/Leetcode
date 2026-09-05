// class Solution {
// private:
//     int lps(string &text1, int index1, string &text2, int index2, unordered_map<string, int> &memo){
//         if(index1 >= text1.length() || index2 >= text2.length())
//             return 0;
//         string key = to_string(index1) + "," + to_string(index2);
//         if(memo.find(key) != memo.end())
//             return memo[key];
        
//         if(text1[index1] == text2[index2]){
//             memo[key] = 1 + lps(text1, index1 + 1, text2, index2 + 1, memo);
//             return memo[key];
//         }
//         memo[key] = max(lps(text1, index1 + 1, text2, index2, memo), lps(text1, index1, text2, index2 + 1, memo));
//         return memo[key];
//     }

// public:
//     int longestPalindromeSubseq(string s) {
//         unordered_map<string, int> memo;
//         string revS = s;
//         reverse(s.begin(), s.end());
//         return lps(s, 0, revS, 0, memo);
//     }
// };

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[n - j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};
