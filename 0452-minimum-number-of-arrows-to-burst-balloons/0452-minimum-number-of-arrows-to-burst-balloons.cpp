class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;
        sort(points.begin(), points.end());
        int startInterval = points[0][0], endInterval = points[0][1];
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] >= startInterval && points[i][0] <= endInterval) {
                endInterval = min(endInterval, points[i][1]);
            } else {
                startInterval = points[i][0];
                endInterval = points[i][1];
                count++;
            }
        }
        return count;
    }
};