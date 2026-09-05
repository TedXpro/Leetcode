class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int price = prices[0];
        for(int p : prices){
            if(p >= price){
                profit += p - price;
                price = p;
            } else
                price = p;
        }

        return profit;
    }
};