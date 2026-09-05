class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        stack<int> st;
        int n = nums.size();

        for(int i = 0; i < n * 2; i++){
            int num = nums[i % n];

            while(!st.empty() && nums[st.top()] < num){
                answer[st.top()] = num;
                st.pop();
            }

            if(i < n)
                st.push(i);
        }
        
        return answer;
    }
};