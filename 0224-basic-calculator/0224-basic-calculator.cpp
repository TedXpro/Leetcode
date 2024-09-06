class Solution {
public:
    int calculate(string s) {
        stack<int> cal;
        int answer = 0, curr = 0, sign = 1;
        for(char ch : s){
            if(isdigit(ch)){
                int num = ch - '0';
                cout << num << endl;
                curr = curr * 10 + num;
                cout << "Curr: " << curr << endl;
            } else if(ch == '+' || ch == '-'){
                answer += curr * sign;
                curr = 0;
                sign = ch == '+' ? 1 : -1;
            } else if(ch == '('){
                cal.push(answer);
                cal.push(sign);
                sign = 1;
                answer = 0;
            } else if(ch == ')'){
                answer += curr * sign;
                answer *= cal.top();
                cal.pop();
                answer += cal.top();
                cal.pop();
                curr = 0;
            }
        }

        return answer + curr * sign;
    }
};