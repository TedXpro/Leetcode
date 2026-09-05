class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> wageToQuality;
        for(int i = 0; i < quality.size(); i++){
            pair<double, int> curr;
            curr.first = wage[i] / quality[i];
            curr.second = quality[i];
            wageToQuality.push_back(curr);
        }

        sort(wageToQuality.begin(), wageToQuality.end());
        priority_queue<int> heap;
        double totalCost = numeric_limits<double>::max();
        double currQuality = 0;
        for(int i = 0; i < wageToQuality.size(); i++){
            heap.push(wageToQuality[i].second);
            
            if(heap.size() > k){
                currQuality -= heap.top();
                heap.pop();
            }
            currQuality += wageToQuality[i].second;
            if(heap.size() == k)
                totalCost = min(totalCost, currQuality * wageToQuality[i].first);
        }
        return totalCost;
    }
};