class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(char c: s){
            letters.insert(c);
        }

        int count = 0;
        for(char letter: letters){
            int start = -1;
            int end = 0;
            for(int k = 0; k < s.size(); k++){
                if(s[k] == letter){
                    if(start == -1)
                        start = k;
                    end = k;
                }
            }

            unordered_set<char> between;
            for(int k = start + 1; k < end; k++)
                between.insert(s[k]);

            count += between.size();

        }

        return count;
    }
};