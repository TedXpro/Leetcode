class Solution {
public:
    int minOperations(string s) {
        /* Space Complexity of O(n) and Time Complexity of O(n) */
        // string sCopy = s;
        // sCopy[0] = s[0] == '0'? '1' : '0';
        // int count = 0;
        // int copyCount = 1;
        // for(int i = 0; i < s.length() - 1; i++){
        //     if(s[i] == s[i + 1]){
        //         count++;
        //         s[i + 1] = s[i] == '1'? '0' :'1';
        //     }
        //     if(sCopy[i] == sCopy[i + 1]){
        //         copyCount++;
        //         sCopy[i + 1] = sCopy[i] == '1'? '0' : '1';
        //     }
        // }
        // return min(copyCount,count);

        /* Space Complexity of O(1) and Time Complexity of O(n) */
        int start0 = 0;
        int start1 = 0;
        for(int i = 0; i < s.length(); i++){
            if(i % 2 == 0)
                s[i] == '1'? start0++ : start1++;
            else 
                s[i] == '0'? start0++ : start1++;
        }
        return min(start0, start1);
    }
};