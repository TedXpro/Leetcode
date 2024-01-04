class Solution {
public:
    int myAtoi(string s) {
        if(s.empty())
            return 0;

        bool negative = false;
        int i = 0;
        while(i < s.length() && s[i] == ' ')
            i++;
        
        if(i == s.length())
            return 0;
        if(s[i] == '-'){
            negative = true;
            i++;
        }
        if(s[i] == '+' && negative)
            return 0;
        else if(s[i] == '+')
            i++;

        long answer = 0;
        while(s[i] >= '0' && s[i] <= '9'){
            answer *= 10;
            answer += s[i] - '0';

            if(negative && -1 * answer < INT_MIN)
                return INT_MIN;
            else if(!negative && answer > INT_MAX)
                return INT_MAX;
            i++;
        }
        
        return negative? -answer : answer;
    }
};