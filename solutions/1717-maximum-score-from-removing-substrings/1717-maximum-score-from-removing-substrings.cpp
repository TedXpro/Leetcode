class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int answer = 0;
        int curr = 0;

        if(x > y){
            for(char &ch : s){
                if(!st.empty() && st.top() == 'a' && ch == 'b'){
                    st.pop();
                    answer += x;
                } else {
                    st.push(ch);
                }
            }
            string remainingChars;
            while (!st.empty()) {
                remainingChars += st.top();
                st.pop();
            }
            reverse(remainingChars.begin(), remainingChars.end());

            for(char &ch : remainingChars){
                if(!st.empty() && st.top() == 'b' && ch == 'a'){
                    st.pop();
                    answer += y;
                } else {
                    st.push(ch);
                }
            }
        } else{
            for(char &ch : s){
                if(!st.empty() && st.top() == 'b' && ch == 'a'){
                    st.pop();
                    answer += y;
                } else {
                    st.push(ch);
                }
            }
            string remainingChars;
            while (!st.empty()) {
                remainingChars += st.top();
                st.pop();
            }
            reverse(remainingChars.begin(), remainingChars.end());

            for(char &ch : remainingChars){
                if(!st.empty() && st.top() == 'a' && ch == 'b'){
                    st.pop();
                    answer += x;
                } else {
                    st.push(ch);
                }
            }
        }
        return answer;
    }
};