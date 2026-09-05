class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string answer = "";
        for(int curr = 0; curr < numRows; curr++){
            int inc = 2 * (numRows - 1);
            for(int i = curr; i < s.length(); i += inc){
                answer += s[i];
                if(curr > 0 && curr < numRows - 1 && i + inc - 2 * curr < s.length()){
                    answer += s[i + inc - 2 * curr];
                }
            }
        }

        return answer;
    }
};