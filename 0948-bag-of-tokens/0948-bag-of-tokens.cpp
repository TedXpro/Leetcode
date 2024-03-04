class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int start = 0, end = tokens.size() - 1;

        while(start < end){
            if(power >= tokens[start]){
                score++;
                power -= tokens[start];
                start++;
            } else {
                if(score == 0)
                    break;
                power += tokens[end];
                score--;
                end--;
            }
        }

        if(start == end && power >= tokens[end])
            score++;

        return score;
    }
};