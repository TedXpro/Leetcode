class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int roll : rolls) {
            sum += roll;
        }

        int remSum = mean * (n + rolls.size()) - sum;

        if (remSum < n || remSum > 6 * n) {
            return {};
        }
        int dist = remSum / n;
        int remDist = remSum % n;
        vector<int> answer(n, dist);
        for (int i = 0; i < remDist; i++) {
            answer[i]++;
        }

        return answer;
    }
};