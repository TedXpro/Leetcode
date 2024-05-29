class Solution {
public:
    int numSteps(string s) {
        int operations = 0;
        int carry = 0;
        for(int i = s.length() - 1; i > 0; i--){
            if(((s[i] - '0') + carry) % 2){
                operations += 2;
                carry = 1;
            } else 
                operations++;
        }
        return operations + carry;
    }
};