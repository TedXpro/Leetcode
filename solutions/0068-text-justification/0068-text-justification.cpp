class Solution {
    string construct(string& curr, int currLength, int maxWidth, int numWords, bool leftJustified){
        if(leftJustified){
            int addSpaces = maxWidth - currLength;;
            for(int i = 0; i < addSpaces; i++){
                curr += " ";
            }
            return curr.substr(0, maxWidth);
        }
        curr = curr.substr(0, curr.length() - 1);
        int addSpaces = maxWidth - currLength;
        int rem = addSpaces % (numWords - 1);
        addSpaces = addSpaces / (numWords - 1);
        string res = "";
        for(char ch : curr){
            if(ch == ' '){
                res += ch;
                for(int i = 0; i < addSpaces; i++){
                    res += ch;
                }
                if(rem > 0){
                    res += ch;
                    rem--;
                }
            } else {
                res += ch;
            }
        }
        return res;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string curr = "";
        int currLength = 0;
        int numWords = 0;
        int total = 0;
        vector<string> answer;
        bool inserted = false;
        for(string &word : words){
            if(currLength + word.length() > maxWidth){
                if(numWords == 1){
                    answer.push_back(construct(curr, currLength - 1, maxWidth, numWords, true));
                }
                else if(total == words.size()){
                    inserted = true;
                    answer.push_back(construct(curr, currLength - 1, maxWidth, numWords, true));
                } else {
                    answer.push_back(construct(curr, currLength - 1, maxWidth, numWords, false));
                }

                curr = word + " ";
                currLength = word.length() + 1;
                numWords = 1;
            } else {
                curr += word + " ";
                numWords++;
                currLength += word.length() + 1;
                total++;
            }
        }

        if(!inserted){
            answer.push_back(construct(curr, currLength - 1, maxWidth, numWords, true));
        }

        return answer;
    }
};