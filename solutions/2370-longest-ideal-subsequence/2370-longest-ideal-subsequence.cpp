class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> memo(27, 0);
        for (int i = s.length() - 1; i >= 0; i--) {
            int currIndex = s[i] - 'a';
            int maxi = INT_MIN + 1;

            int left = max((currIndex - k), 0);
            int right = min((currIndex + k), 26);

            for (int j = left; j <= right; j++) 
                maxi = max(maxi, memo[j]);

            memo[currIndex] = maxi + 1;
        }

        int answer = INT_MIN + 1;
        for (int i = 0; i < 27; i++) {
            if (memo[i] > answer)
                answer = memo[i];
        }

        return answer;
    }
};