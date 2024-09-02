class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        // iterate from left to right;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }

        // iterate from right to left;
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candies[i] = candies[i + 1] + 1;
            }
        }

        int answer = 0;
        for(int candy : candies){
            answer += candy;
        }

        return answer;
    }
};