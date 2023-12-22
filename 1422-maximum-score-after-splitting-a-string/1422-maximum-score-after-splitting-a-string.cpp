class Solution {
public:
    int maxScore(string s) {
        int left = s[0] == '0'? 1 : 0;
        int right = 0;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == '1')
                right++;
        }

        int maximum = left + right;
        for(int i = 1; i < s.length() - 1; i++){
            if(s[i] == '0')
                left++;
            else 
                right--;
            maximum = max(left + right, maximum);
        }
        return maximum;
    }
};