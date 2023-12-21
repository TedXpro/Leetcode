class Solution {
public:
    int countHomogenous(string s) {
        long count = 0;

        for(int i = 0; i < s.length(); i++){
            int j = i;
            long substring = 0;
            for(; j < s.length(); j++){
                if(s[i] == s[j]){
                    substring++;
                    count += substring;
                }
                else
                    break;
            }
            i = j - 1;
        }
        return (int)(count % (long)(pow(10, 9) + 7));
    }
};