class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> memo;
        for(string &dict : dictionary)
            memo.insert(dict);
        istringstream srr(sentence);
        vector<string> sentArray;
        string curr = "";
        while(getline(srr, curr, ' ')){
            sentArray.push_back(curr);
        }

        string answer = "";
        for(string curr : sentArray){
            bool entered = false;
            for(int i = 0; i < curr.length(); i++){
                if(memo.find(curr.substr(0,i)) != memo.end()){
                    answer += curr.substr(0, i) + " ";
                    entered = true;
                    break;
                }
            }
            if(!entered)
                answer += curr + " ";
        }
        return answer.substr(0, answer.length() - 1);
    }
};