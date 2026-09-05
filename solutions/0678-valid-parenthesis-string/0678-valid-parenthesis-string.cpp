class Solution {
public:
    bool checkValidString(string s) {
        int useAsterix = 0, dontUseAsterix = 0;
        for(char ch : s){
            if(ch == '('){
                useAsterix++;
                dontUseAsterix++;
            } else if(ch == ')'){
                useAsterix--;
                dontUseAsterix--;
            } else {
                useAsterix--;
                dontUseAsterix++;
            } 
            if(dontUseAsterix < 0)
                return false;

            if(useAsterix < 0)
                useAsterix = 0;
        }

        return true;
    }
};