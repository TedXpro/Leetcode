class Solution {
public:
    int minChanges(string s) {
        int answer = 0;
        int currCount = 0;
        char currChar = s[0];
        for(char ch : s){
            if(currChar == ch){
                currCount++;
                continue;
            } 

            if(currCount % 2 == 0){
                currCount = 1;
            } else {
                currCount = 0;
                answer++;
            }

            currChar = ch;
        }

        return answer;
    }
};