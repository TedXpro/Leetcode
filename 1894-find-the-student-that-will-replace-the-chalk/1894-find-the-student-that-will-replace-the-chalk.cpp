class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long prefix = 0;
        for(int i = 0; i < chalk.size(); i++){
            prefix += chalk[i];
        }
        k = k % prefix;
        for(int i = 0; i < chalk.size(); i++){
            if(k < chalk[i]){
                return i;
            }
            k -= chalk[i];
        }

        return -1;
    }
};