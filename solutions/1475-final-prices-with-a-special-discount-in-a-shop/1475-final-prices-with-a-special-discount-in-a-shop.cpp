class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer = prices;
        stack<int> monotone;
        for(int i = 0; i < prices.size(); i++){
            while(!monotone.empty() && prices[monotone.top()] >= prices[i]){
                answer[monotone.top()] -= prices[i];
                monotone.pop();
            }

            monotone.push(i);
        }

        return answer;
    }
};