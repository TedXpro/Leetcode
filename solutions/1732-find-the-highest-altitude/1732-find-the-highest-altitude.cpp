class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = gain[0];
        int maxElevation = max(0, sum);
        for(int i = 1; i < gain.size(); i++){
            sum += gain[i];
            maxElevation = max(maxElevation, sum);
        }
        return maxElevation;
    }
};