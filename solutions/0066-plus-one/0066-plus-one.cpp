class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // space complexity of O(1)
        int size = digits.size();
        digits[size - 1] = digits[size - 1] + 1;
        int rem = digits[size - 1] / 10;
        digits[size - 1] = digits[size - 1] % 10;
        for(int i = size - 2; i >= 0; i--){
            if(rem == 0)
                return digits;
            int val = digits[i] + rem;
            digits[i] = val % 10;
            rem = val / 10;
        }

        if (rem != 0){
            digits.insert(digits.begin(), rem);
        }

        return digits;


        // space complexity of O(n)
        // int size = digits.size();
        // if(digits[size - 1] + 1 < 10){
        //     digits[size - 1]  += 1;
        //     return digits;
        // } 
        // vector<int> newDigits;
        // int rem = (digits[size - 1] + 1) / 10;
        // newDigits.push_back((digits[size - 1] + 1) % 10);
        
        // for(int i = size - 2; i >= 0; i--)
        // {
        //     newDigits.push_back((digits[i] + rem) % 10);
        //     rem = (digits[i] + rem) / 10;
        // }
        // if(rem != 0)
        //     newDigits.push_back(rem);
            
        // for(int start = 0, end = newDigits.size() - 1; start < end; start++, end--){
        //     int temp = newDigits[start];
        //     newDigits[start] = newDigits[end];
        //     newDigits[end] = temp;
        // }
        // return newDigits;
    }
};