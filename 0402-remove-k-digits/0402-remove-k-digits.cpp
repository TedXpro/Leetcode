class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char ch : num){
            while(k > 0 && !st.empty() && st.top() > ch){
                st.pop();
                k--;
            }
            
            st.push(ch);
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        string answer = "";
        while(!st.empty()){
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        auto index = answer.find_first_not_of('0');
        answer = index == string::npos ? "0" : answer.substr(index);
        return answer;
    }
};