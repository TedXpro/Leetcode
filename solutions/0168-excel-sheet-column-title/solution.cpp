class Solution {
private:
    static inline string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
     
    string convertToTitle(int columnNumber) {
        string answer = "";
    
        while (columnNumber > 0) {
            columnNumber--; 
            
            int rem = columnNumber % 26;
            answer = alphabet[rem] + answer;
            
            columnNumber /= 26;
        }
        
        return answer;
    }
};

