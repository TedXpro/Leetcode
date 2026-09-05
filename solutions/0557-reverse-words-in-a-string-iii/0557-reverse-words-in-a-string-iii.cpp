class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        ostringstream answer;
        while(getline(iss, word, ' ')){
            reverse(word.begin(), word.end());
            answer << word << " "; 
        }

        
        return answer.str().substr(0, s.length());
    }
};