class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest = min(prices[0], prices[1]);
        int secondSmallest = max(prices[0], prices[1]);
        for(int i = 2; i < prices.size(); i++){
            if(prices[i] <= smallest){
                secondSmallest = smallest;
                smallest = prices[i];
            }
            else 
                secondSmallest = min(secondSmallest, prices[i]);
        }

        return secondSmallest + smallest > money ? money : money - (smallest + secondSmallest);
    }
};