class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(); 
        vector<pair<int, int>> st(n);
        for(int i = 0; i < n; i++) 
            st[i] = {startTime[i], i};

        sort(st.begin(), st.end());
        vector<int> dp(n+1, 0); 
        for(int i = n-1; i >= 0; i--)
            dp[i] += max(dp[i+1], profit[st[i].second] + 
            dp[lower_bound(st.begin() + i, st.end(), make_pair(endTime[st[i].second], 0)) - st.begin()]);
        return dp[0];
    }
};