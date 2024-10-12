class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> intervalPairs;
        for (vector<int> interval : intervals) {
            intervalPairs.push_back({interval[0], 1});
            intervalPairs.push_back({interval[1] + 1, -1});
        }

        sort(intervalPairs.begin(), intervalPairs.end());

        int count = 0;
        int answer = 0;
        for (auto p : intervalPairs) {
            count += p.second;
            answer = max(answer, count);
        }

        return answer;
    }
};