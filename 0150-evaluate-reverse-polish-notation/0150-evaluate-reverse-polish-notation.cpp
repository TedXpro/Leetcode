class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string str : tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(str == "+")
                    st.push(b + a);
                else if(str == "-")
                    st.push(b - a);
                else if(str == "*")
                    st.push(b * a);
                else 
                    st.push(b / a);
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};