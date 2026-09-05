class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int number = prices[0];
        for(int i =1; i< prices.size(); i++)
        {
            if(number > prices[i])
                number = prices[i];
            else 
            {
                if(maxProfit < prices[i] - number)
                    maxProfit = prices[i]-number;
            }
        }

        return maxProfit;
    }


};