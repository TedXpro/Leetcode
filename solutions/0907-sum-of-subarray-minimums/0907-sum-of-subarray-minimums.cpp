class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long answer = 0;
        stack<int> st;  // Stack to maintain indices

        for (int i = 0; i <= arr.size(); i++) {
            while (!st.empty() && (i == arr.size() || arr[i] < arr[st.top()])) {
                // Calculate the sum for the popped index
                int index = st.top();
                st.pop();
                int left = (index - (st.empty() ? -1 : st.top())) % MOD;
                int right = (i - index) % MOD;
                answer = (answer + static_cast<long long>(arr[index]) * left * right) % MOD;
            }
            st.push(i);
        }

        return static_cast<int>(answer % MOD);
    }
};
