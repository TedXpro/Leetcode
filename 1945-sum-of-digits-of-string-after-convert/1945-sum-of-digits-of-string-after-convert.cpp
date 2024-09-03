class Solution {
    int convertToInteger(string & s){
        string ans;
        for(char c : s){
            if(islower(c)){
                int number = c - 'a' + 1;
                ans += to_string(number);
            }
        }
        int sum = 0; 
        for(char c : ans)  
            sum += c - '0';
        return sum;
    }

    int addDigits(int num){
        int sum = 0;
        while(num > 0){
            int rem = num % 10;
            sum += rem;
            num = num / 10;
        }
        return sum;
    }

public:
    int getLucky(string s, int k) {
        int num = convertToInteger(s);

        for(int i = 1; i < k; i++){
            num = addDigits(num);
            if(num < 10)
                break;
        }
        return num;
    }
};