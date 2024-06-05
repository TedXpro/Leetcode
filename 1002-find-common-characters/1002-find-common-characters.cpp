class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26), current(26);
        for(char ch : words[0]){
            common[ch - 'a']++;
        }

        for(int i = 1; i < words.size(); i++){
            fill(current.begin(), current.end(), 0);
            for(char ch : words[i])
                current[ch - 'a']++;
            
            for(int j = 0; j < 26; j++)
                common[j] = min(common[j], current[j]);
        }

        vector<string> answer;
        for(int i = 0; i < 26; i++){
            for(int letterCount = 0; letterCount < common[i]; letterCount++)
                answer.push_back(string(1, i + 'a'));
        }

        return answer;
    }
};