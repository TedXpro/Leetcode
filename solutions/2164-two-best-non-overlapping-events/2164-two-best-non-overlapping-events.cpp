class Solution {
private:
    int findEvents(vector<vector<int>>& events, int index, int count, vector<vector<int>>& memo){
        if(count == 2 || index >= events.size()){
            return 0;
        }

        if(memo[index][count] == -1){
            int end = events[index][1];
            int lo = index + 1, hi = events.size() - 1;
            while(lo < hi){
                int mid = lo + ((hi - lo) >> 1);
                if(events[mid][0] > end){
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            int include = events[index][2] + (lo < events.size() && events[lo][0] > end ? findEvents(events, lo, count + 1, memo) : 0);
            int exclude = findEvents(events, index + 1, count, memo);
            memo[index][count] = max(include, exclude);
        }
        
        return memo[index][count];
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> memo(events.size(), vector<int>(3, -1));
        return findEvents(events, 0, 0, memo);
    }
};