class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> memo;
        string curr = "";
        for(char s : s1){
            if(s == ' '){
                memo[curr]++;
                curr = "";
            } else {
                curr += s;
            }
        }

        memo[curr]++;
        curr = "";
        for(char s : s2){
            if(s == ' '){
                memo[curr]++;
                curr = "";
            } else {
                curr += s;
            }
        }
        memo[curr]++;
        
        vector<string> answer;
        for(auto& m : memo){
            cout << m.first << " " << m.second << endl;
            if(m.second == 1){
                answer.push_back(m.first);
            }
        }

        return answer;
    }
};