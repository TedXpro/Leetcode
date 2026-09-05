#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int mod = 1'000'000'007;

    int dfs(int end, int zero, int one) {
        if (dp[end] != -1) {
            return dp[end];
        }

        int count = 0;
        if (end >= one) {
            count = (count + dfs(end - one, zero, one)) % mod;
        }
        if (end >= zero) {
            count = (count + dfs(end - zero, zero, one)) % mod;
        }

        dp[end] = count;
        return dp[end];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector<int>(high + 1, -1); 
        dp[0] = 1;

        int answer = 0;
        for (int end = low; end <= high; ++end) {
            answer = (answer + dfs(end, zero, one)) % mod;
        }

        return answer;
    }
};
