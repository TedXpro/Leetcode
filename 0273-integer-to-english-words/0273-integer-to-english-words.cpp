class Solution {
private:
    string toWords(int num){
        if(num < 10){
            return ones[num];
        }
        if(num < 20){
            return belowTwenty[num - 10];
        }
        if(num < 100){
            return tens[num / 10] + (num % 10 ? " " + toWords(num % 10) : "");
        }
        if(num < 1000){
            return toWords(num / 100) + " Hundred" + (num % 100 ? " " + toWords(num % 100) : "" );
        } 
        if(num < 1000000){
            return toWords(num / 1000) + " Thousand" + (num % 1000 ? " " + toWords(num % 1000) : "");
        }
        if(num < 1000000000){
            return toWords(num / 1000000) + " Million" + (num % 1000000 ? " " + toWords(num % 1000000) : "");
        }
        return toWords(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + toWords(num % 1000000000) : "");
    }
public:
    const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }

        return toWords(num);
    }
};