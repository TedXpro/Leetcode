class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        for(int i = 0; i < colors.length() - 1; i++){
            int j = i + 1;
            int maxi = neededTime[i];
            time += neededTime[i];
            while(colors[i] == colors[j]){
                time += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }
            time -= maxi;
            i = j - 1;
        }
        return time;
    }
};