class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        int totalWords = words.size();  
        int len = words[0].length();

        if(s.length() < len * totalWords){
            return answer;
        }

        unordered_map<string, int> allWords;
        for(string &word : words){
            allWords[word]++;
        }

        for(int index = 0; index < len; index++){
            int start = index;
            unordered_map<string, int> seen;
            int currLength = 0;
            
            for(int i = index; i <= s.length() - len; i += len){
                string curr = s.substr(i, len);
                if(allWords.find(curr) != allWords.end()){
                    seen[curr]++;
                    currLength++;
                    while(seen[curr] > allWords[curr]){
                        string left = s.substr(start, len);
                        seen[left]--;
                        currLength--;
                        start += len;
                    } 
                    
                    if(currLength == totalWords){
                        answer.push_back(start);
                        string left = s.substr(start, len);
                        seen[left]--;
                        currLength--;
                        start += len;
                    } 
                } else {
                    seen.clear();
                    currLength = 0;
                    start = i + len;
                }
            }
        }
        return answer;
    }
};