class Solution {
public:
    int numDecodings(string s) {
        vector<int> answer(s.size() + 1, 0);
        answer[s.size()] = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] != '0')
                answer[i] += answer[i + 1];
            if(i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                answer[i] += answer[i + 2];
        }
        return answer[0];
    }
};