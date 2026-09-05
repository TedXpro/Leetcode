class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string answer = "";
        int ones = 0, zeros = 0;
        for(char ch : s){
            if(ch == '1')
                ones++;
            else 
                zeros++;
        }

        answer += string(ones - 1, '1');
        answer += string(zeros, '0');
        answer += '1';
        return answer;
    }
};