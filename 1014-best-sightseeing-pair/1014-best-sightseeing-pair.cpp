class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int>maxScore(values.size());
        maxScore[0] = values[0];
        int answer = 0;
        for(int i = 1; i < values.size(); i++){
            int currRight = values[i] - i;
            answer = max(answer, maxScore[i - 1] + currRight);

            int currLeft = values[i] + i;
            maxScore[i] = max(maxScore[i - 1], currLeft); 
        }

        return answer;
    }
};