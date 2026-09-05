// class Solution {
// public:
//     int getLengthOfOptimalCompression(string s, int k) {
//         int n = s.size();
//         int m = k;

//         // int ans[110][110] = {};
//         vector<vector<int>> ans (110, vector<int>(110));
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 0; j <= i && j <= m; ++j) {
//                 int remove = 0;
//                 int count = 0;
//                 ans[i][j] = INT_MAX;
//                 if (j) {
//                     ans[i][j] = ans[i - 1][j - 1];
//                 }
//                 for (int k = i; k >= 1; --k) {
//                     if (s[k - 1] != s[i - 1]) 
//                         remove += 1;
//                     else 
//                         count += 1;
//                     if (remove > j) 
//                         break;

//                     if (count == 1) 
//                         ans[i][j] = min(ans[i][j], ans[k - 1][j - remove] + 1);
//                     else if (count < 10)
//                         ans[i][j] = min(ans[i][j], ans[k - 1][j - remove] + 2);
//                     else if (count < 100)
//                         ans[i][j] = min(ans[i][j], ans[k - 1][j - remove] + 3);
//                     else
//                         ans[i][j] = min(ans[i][j], ans[k - 1][j - remove] + 4);
//                 }
//             }
//         }

//         return ans[n][m];
//     }
// };

class Solution {
private:
    int memo[101][101];

    int recursion(const string &s, int i, int K){
        int n = s.length(), k = K;
        if(n-i<=k) 
            return 0;
        if(memo[i][k]!=-1) 
            return memo[i][k];
        int ans = k ? recursion(s, i+1 , k-1) : 101, c = 1;
		
        for(int j=i+1 ; j <= n ; j++){
            ans = min( ans, 1 + ((c > 99) ? 3 : (c > 9) ? 2 : (c > 1) ? 1 : 0) 
            + recursion(s, j, k));

            if(j < n && s[i] == s[j]) 
                c++;
            else if(--k < 0) 
                break;
        }
        return memo[i][K] = ans;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(memo,-1,sizeof(memo));
        return recursion(s, 0, k);
    }
};