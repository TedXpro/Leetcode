class Solution {
    void generate(vector<string> &answer, int n, string curr, int open, int close){
        if(curr.length() == 2 * n){
            answer.push_back(curr);
            return;
        }

        if(open < n)
            generate(answer, n, curr + "(", open + 1, close);
        if(close < open)
            generate(answer, n, curr + ")", open, close + 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        generate(answer, n, "", 0, 0);
        return answer;
    }
};