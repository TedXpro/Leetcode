class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // vector<int> xPoints;
        // for(int i = 0; i < points.size(); i++)
        //     xPoints.push_back(points[i][0]);

        // sort(xPoints.begin(), xPoints.end());
        // int diff = 0;
        // for(int i = 1; i < xPoints.size(); i++)
        //     diff = max(diff, xPoints[i] - xPoints[i - 1]);
        
        // return diff;

        sort(points.begin(), points.end());

        int diff = 0;
        for(int i = 1; i < points.size(); i++)
            diff = max(diff, points[i][0] - points[i - 1][0]);

        return diff;
    }
};