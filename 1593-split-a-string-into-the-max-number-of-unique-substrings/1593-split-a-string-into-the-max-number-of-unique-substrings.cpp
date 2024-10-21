class Solution {
private:
    int findUnique(string s, unordered_set<string>& memo, int index){
        if(index == s.length()){
            return 0;
        }

        int currAnswer = 0;
        for(int i = index; i < s.length(); i++){
            string substr = s.substr(index, i + 1 - index);
            if(memo.find(substr) != memo.end()){
                continue;
            }

            memo.insert(substr);
            currAnswer = max(currAnswer, 1 + findUnique(s, memo, i + 1));
            memo.erase(substr);
        }

        return currAnswer;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> memo;

        return findUnique(s, memo, 0);
    }
};