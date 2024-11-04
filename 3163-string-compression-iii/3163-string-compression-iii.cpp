class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        for(int i = 0; i < word.length(); ){
            char currChar = word[i];
            int count = 0;
            while(count < 9 && i < word.length() && word[i] == currChar){
                count++;
                i++;
            }
            comp += to_string(count) + currChar;
        }

        return comp;
    }
};