class Solution {
private:
    int search(vector<vector<int>>& items, int target){
        int start = 0, end = items.size() - 1;
        int maxB = 0;
        while(start <= end){
            int mid = (start + end) / 2;
            if(items[mid][0] > target){
                end = mid - 1;
            } else {
                maxB = max(maxB, items[mid][1]);
                start = mid + 1;
            }
        }

        return maxB;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        int maxB = items[0][1];
        for(int i = 0; i < items.size(); i++){
            maxB = max(maxB, items[i][1]);
            items[i][1] = maxB;
        }    

        vector<int> answer;

        for(int query : queries){
            answer.push_back(search(items, query));
        }

        return answer;
    }
};