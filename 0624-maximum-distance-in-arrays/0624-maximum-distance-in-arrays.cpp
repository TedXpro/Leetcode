class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int answer = 0;
        int maxNum = arrays[0][arrays[0].size() - 1];
        int minNum = arrays[0][0];
        for(auto & arr : arrays){
            answer = max(answer, max(maxNum - arr[0], arr[arr.size() - 1] - minNum));
            maxNum = max(maxNum, arr[arr.size() - 1]);
            minNum = min(minNum, arr[0]);
        }

        return answer;
    }
};