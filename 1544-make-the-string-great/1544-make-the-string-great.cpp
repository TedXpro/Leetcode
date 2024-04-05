class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char ch : s){
            if(!st.empty() && (abs(ch - st.top()) == 32))
                st.pop();
            else 
                st.push(ch);
        }

        ostringstream answer;
        while(!st.empty()){
            answer << st.top();
            st.pop();
        }
        string ans = answer.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};