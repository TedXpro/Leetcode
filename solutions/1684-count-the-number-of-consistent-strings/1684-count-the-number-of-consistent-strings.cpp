class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> all;
        for(char ch : allowed){
            all.insert(ch);
        }

        int count = 0;
        for(string& word : words){
            bool repeated = false;
            for(char ch : word){
                if(all.find(ch) == all.end()){
                    repeated = true;
                    break;
                }
            }

            if(!repeated){
                count++;
            }
        }

        return count;
    }
};