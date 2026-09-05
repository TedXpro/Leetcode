class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> memo;
        for(char ch : s)
            memo[ch]++;
        int oddSeen = 0;
        int answer = 0;
        for(auto& m : memo){
            if(m.second % 2 != 0){
                answer += (m.second - 1);
                oddSeen = 1;
            }
            else 
                answer += m.second;    
        }   
        answer += oddSeen == 1 ? 1 : 0;
        return answer;
    }
};