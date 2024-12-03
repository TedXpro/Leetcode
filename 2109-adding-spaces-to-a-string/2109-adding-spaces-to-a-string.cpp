class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        if(spaces.size() == 0)
            return s;
        string answer = "";
        int counter = 0;
        for(int i = 0; i < spaces.size(); i++){
            answer += s.substr(counter,spaces[i] - counter) + " ";
            counter = spaces[i];
        }
        if(counter < s.length())
            answer += s.substr(counter, s.length());
        return answer;
    }
};