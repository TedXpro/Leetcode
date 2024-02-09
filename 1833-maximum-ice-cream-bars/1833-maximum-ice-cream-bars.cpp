class Solution {
private:
    void countingSort(vector<int>& costs){
        int mini = INT_MAX, maxi = 0;
        for(int cost : costs){
            mini = min(mini, cost);
            maxi = max(maxi, cost);
        }

        vector<int> countArray(maxi - mini + 1,0);
        for(int cost : costs)
            countArray[cost - mini]++;
        
        for(int i = 1; i < countArray.size(); i++)
            countArray[i] += countArray[i - 1];
        
        vector<int> sortedCosts(costs.size());
        for(int cost : costs){
            sortedCosts[countArray[cost - mini] - 1] = cost;
            countArray[cost - mini]--;
        }

        costs = sortedCosts;
        sortedCosts.clear();
    }
public:
    int maxIceCream(vector<int>& costs, int coins) {
        countingSort(costs);
        int count = 0;
        for(int cost : costs){
            if(cost <= coins){
                count++;
                coins -= cost;
            }
        }

        return count;
    }
};