// class Solution {
//     map<vector<int>, int> cache;
//     int findMin(vector<int>& jobDifficulty, int index, int day, int currMax){
//         if(index == jobDifficulty.size())
//             return day == 0? 0 : 1e9;
//         if(day == 0)
//             return 1e9;
//         if(cache.contains({index, day, currMax}))
//             return cache[{index, day, currMax}];

//         currMax = max(currMax, jobDifficulty[index]);

//         int result = min(findMin(jobDifficulty, index + 1, day, currMax), 
//         findMin(jobDifficulty, index + 1, day - 1, -1) + currMax);

//         cache[{index, day, currMax}] = result;
//         return result;
//     }
// public:
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         if(d > jobDifficulty.size())
//             return -1;
//         return findMin(jobDifficulty, 0, d, -1);
//     }
// };

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n)
            return -1;

        vector<vector<int>> memo(n + 1, vector<int>(d + 1, INT_MAX));
        memo[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= d; ++k) {
                int currMax = 0;
                for (int j = i - 1; j >= 0 && k <= i; --j) {
                    currMax = max(currMax, jobDifficulty[j]);
                    if (memo[j][k - 1] != INT_MAX && currMax != INT_MAX / 5)
                        memo[i][k] = min(memo[i][k], memo[j][k - 1] + currMax);
                }
            }
        }

        return memo[n][d] == INT_MAX ? -1 : memo[n][d];
    }
};
