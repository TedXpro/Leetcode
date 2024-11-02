class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.length() == 1){
            return true;
        }
        if(sentence[0] != sentence[sentence.length() - 1]){
            return false;
        }
        
        char firstChar = sentence[0];
        char lastChar = sentence[0];
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == ' '){
                cout << lastChar << " : " << sentence[i + 1] << endl;
                if(lastChar != sentence[i + 1]){
                    return false;
                }
                i++;
            }

            lastChar = sentence[i];
        } 

        return true;
    }
};