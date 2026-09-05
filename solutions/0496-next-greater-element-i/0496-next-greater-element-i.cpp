class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> memo;
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top())
                st.pop();
            
            if(st.empty())
                memo[nums2[i]] = -1;
            else 
                memo[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }

        vector<int> answer;
        for(int nums : nums1)
            answer.push_back(memo[nums]);
        
        return answer;
    }
};