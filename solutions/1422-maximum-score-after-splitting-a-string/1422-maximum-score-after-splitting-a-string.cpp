class Solution {
public:
    int maxScore(string s) {
        int one = 0;
        for(char ch : s){
            if (ch == '1'){
                one++;
            }
        }

        int answer = 0;
        int zero = 0;
        for (int i = 0; i < s.length() - 1; i++){
            if(s[i] == '1'){
                one--;
            } else {
                zero++;
            }

            answer = max(answer, one + zero);
        }

        return answer;
    }
};