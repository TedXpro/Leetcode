class Solution {
public:
    string makeFancyString(string s) {
        if(s.length() < 3){
            return s;
        }

        string answer = "";
        
        char curr = s[0];
        answer += curr;
        int count = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] != curr){
                curr = s[i];
                count = 1;
                answer += s[i];
                continue;
            }
            if(s[i] == curr && ++count == 3){
                int index = i + 1;
                while(index < s.length() && s[index] == curr){
                    index++;
                }
                i = index - 1;
                count = 0;
                curr = s[index];
            } else {
                answer += s[i];
            }
        }

        return answer;
    }
};