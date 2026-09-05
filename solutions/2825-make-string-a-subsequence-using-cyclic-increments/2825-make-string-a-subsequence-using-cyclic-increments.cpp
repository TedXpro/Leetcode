class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.length() > str1.length()){
            return false;
        }

        for(int i1 = 0, i2 = 0; i2 < str2.length(); i1++){
            if(i1 >= str1.length()){
                return false;
            }

            if(str1[i1] == str2[i2]){
                i2++;
                continue;
            } else if(str1[i1] + 1 == str2[i2]){
                i2++;
                continue;
            } else if(str1[i1] - 25 == str2[i2]){
                i2++;
                continue;
            } 
        }

        return true;
    }
};