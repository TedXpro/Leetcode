class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream os(sentence);
        string currStr;
        int count = 1;
        while(os >> currStr){
            if(currStr.find(searchWord) == 0){
                return count;
            }
            count++;
        }

        return -1;
    }
};