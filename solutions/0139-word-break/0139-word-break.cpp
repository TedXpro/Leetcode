class Solution {
private:
    bool breakWords(string s, vector<string>& wordDict, unordered_map<string, bool> &memo){
        if(s == "")
            return true;
        if(memo.find(s) != memo.end())
            return memo[s];

        for(string word : wordDict){
            if(s.find(word) == 0){
                if(breakWords(s.substr(word.length()), wordDict, memo)){
                    memo[s] = true;
                    return true;
                }
            }
        }

        memo[s] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo;

        return breakWords(s, wordDict, memo);
    }
};