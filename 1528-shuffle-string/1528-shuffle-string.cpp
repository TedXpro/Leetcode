class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string answer (s.length(), ' ');
        for(int i = 0; i < indices.size(); i++){
            answer[indices[i]] = s[i];
        }
        return answer;
    }
};