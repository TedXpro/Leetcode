class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        vector<string>directories;
        string dir;
        while(getline(iss, dir, '/'))
            directories.push_back(dir);
        
        stack<string> st;
        for(string &dir : directories){
            if(dir == "." || dir == "")
                continue;
            if(dir == ".."){
                if(!st.empty())
                    st.pop();
            }
            else 
                st.push(dir);
        }

        string answer = "";
        while(!st.empty()){
            answer = "/" + st.top() + answer;
            st.pop();
        }
        return answer.empty() ? "/" : answer;
    }
};