class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        s += s;
        cout << s.find(goal);
        return s.find(goal) < s.length();
    }
};