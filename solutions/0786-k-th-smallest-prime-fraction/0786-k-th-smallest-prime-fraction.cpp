class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> heap;
        for(int i = 0; i < arr.size(); i++)
            heap.push({-1.0 * arr[i] / arr[arr.size() - 1], {i, arr.size() - 1}});

        while(--k > 0){
            pair<int, int> curr = heap.top().second;
            heap.pop();
            curr.second--;
            heap.push({-1.0 * arr[curr.first] / arr[curr.second], {curr.first, curr.second}});
        }

        pair<int, int> answer = heap.top().second;
        return vector<int>{arr[answer.first], arr[answer.second]};
    }
};