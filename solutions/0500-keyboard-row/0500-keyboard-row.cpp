class Solution {
    bool checkRow(string s, set<char> row){
        for(int i = 1; i < s.length(); i++){
            if(row.find(tolower(s[i])) == row.end())
                return false;
        }
        return true;
    }
public:
    vector<string> findWords(vector<string>& words) {
        set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
        set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
        set<char> row3 = {'z','x','c','v','b','n','m'};

        vector<string> answer;
        for(int i = 0; i < words.size(); i++){
            if(row1.find(tolower(words[i][0])) != row1.end()){
                if(checkRow(words[i], row1))
                    answer.push_back(words[i]);
            }
            else if(row2.find(tolower(words[i][0])) != row2.end()){
                if(checkRow(words[i], row2))
                    answer.push_back(words[i]);
            }
            else if(row3.find(tolower(words[i][0])) != row3.end()){
                if(checkRow(words[i], row3))
                    answer.push_back(words[i]);
            }
        }
        return answer;
    }
};