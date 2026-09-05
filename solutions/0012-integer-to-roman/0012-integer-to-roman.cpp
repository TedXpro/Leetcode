class Solution {
public:
    string intToRoman(int num) {
        vector<char> integerRoman = {'I','V','X','L','C','D','M'};
        int low = 0, high = 2;
        string answer;
        while(num > 0){
            int rem = num % 10;
            string temp = "";
            if(rem > 0 && rem < 4){
                while(rem > 0){
                    temp += integerRoman[low];
                    rem--;
                }
                answer = temp + answer;
            }
            else if(rem == 4){
                temp += integerRoman[low];
                temp += integerRoman[low + 1];
                answer = temp + answer;
                
            }
            else if(rem > 4 && rem < 9){
                temp += integerRoman[low + 1];
                int r = rem - 5;
                while(r > 0){
                    temp += integerRoman[low];
                    r--;
                }
                answer = temp + answer;
            }
            else if(rem == 9){
                temp += integerRoman[low];
                temp += integerRoman[high];
                answer = temp + answer;
            }
            low+= 2;
            high += 2;
            num /= 10;
        }
        
        return answer;
    }
};