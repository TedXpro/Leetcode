class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer = 0;
        int pow = 0;
        for (int i = columnTitle.length() - 1; i >= 0; i--){
            char ch = columnTitle[i];
            answer += ((std::pow(26, pow)) * (ch - 'A' + 1)); 
            pow++;
        }
        return answer;
    }
};