class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> memo;
        for(char ch : s){
            memo[ch]++;
        }

        int answer = 0;
        for(auto m : memo){
            if(m.second <= 2){
                answer += m.second;
            } else if(m.second % 2 == 0) {
                answer += 2;
            } else {
                answer += 1;
            }
        }

        return answer;
    }
};