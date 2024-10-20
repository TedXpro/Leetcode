class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> exp;
        stack<char> operators;
        for(char ch : expression){
            if(ch == '!' || ch == '&' || ch == '|'){
                operators.push(ch);
            } else if(ch == '('){
                exp.push(ch);
            } else if(ch == ')'){
                if(operators.top() == '!'){
                    char curr = exp.top();
                    exp.pop();
                    curr = curr == 'f' ? 't' : 'f';
                    exp.push(curr);
                }
                operators.pop();
            } else if(isalpha(ch)){
                if(isalpha(exp.top())){
                    bool curr = exp.top() == 'f' ? 0 : 1;
                    exp.pop();
                    if(operators.top() == '&'){
                        curr &= (ch == 'f' ? 0 : 1);
                    } else if(operators.top() == '|'){
                        curr |= (ch == 'f' ? 0 : 1);
                    }
                    char currCh = curr ? 't' : 'f';
                    exp.push(currCh);
                } else {
                    exp.push(ch);
                }
            }

        }
        return exp.top() == 'f' ? false : true;
    }
};