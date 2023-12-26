class Solution {
    double getArea(vector<int> v1, vector<int> v2, vector<int> v3){
        return (v1[0] * (v2[1] - v3[1]) + v2[0] * (v3[1] - v1[1]) + v3[0] * (v1[1] - v2[1])) / 2.0;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    double tempArea = abs(getArea(points[i], points[j], points[k]));
                    maxArea = max(maxArea, tempArea);
                }
            }
        }

        return maxArea;
    }
};