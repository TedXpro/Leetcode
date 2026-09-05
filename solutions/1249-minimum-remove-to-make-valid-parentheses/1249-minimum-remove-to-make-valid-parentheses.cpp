class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> indices;
        for(int i = 0; i < s.length(); i++){
            if((s[i] == '(' || s[i] == ')')){
                if(!indices.empty() && s[i] == ')' && s[indices.top()] == '(')
                    indices.pop();
                else 
                    indices.push(i);
            }
        }   

        // string ans = "";
        // int i = s.length() .- 1;
        while(!indices.empty()){
            s[indices.top()] = '#';
            indices.pop();
        }
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};