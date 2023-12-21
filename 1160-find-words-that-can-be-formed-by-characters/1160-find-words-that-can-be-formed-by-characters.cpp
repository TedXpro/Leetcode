class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> existence;
        for(char ch : chars){
            if(existence.contains(ch))
                existence[ch]++;
            else 
                existence[ch] = 1;
        }
        
        int counter = 0;
        for(string word : words){
            bool status = true;
            map<char, int> copyExistence(existence.begin(), existence.end());
            for(char ch : word){
                if(copyExistence.contains(ch) && copyExistence[ch] > 0)
                    copyExistence[ch]--;
                else{ 
                    status = false;
                    break;
                }
            }
            if(status)
                counter += word.length();
        }
        return counter;
    }
};