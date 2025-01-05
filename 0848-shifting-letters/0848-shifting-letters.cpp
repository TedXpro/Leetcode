// class Solution {
// public:
//     string shiftingLetters(string s, vector<int>& shifts) {
//         vector<long long> currShifts(shifts.size(), shifts[shifts.size() - 1]);
//         for(int i = currShifts.size() - 2; i >= 0; i--){
//             currShifts[i] = shifts[i] + currShifts[i + 1];
//         }

//         for(int i = 0; i < currShifts.size(); i++){
//             cout << "Curr Character: " << s[i] << "  CurrShift Value: " << currShifts[i] << endl;
//             int asciVal = s[i] - 'a';
//             cout << "ASCII_VAL: " << asciVal << " AFTER: " << (asciVal + 97) << endl;
//             long long curr = asciVal + 97 + currShifts[i];
//             cout << "Before: " << curr << endl;
//             if(curr > 122){
//                 int rem = (curr - 96) % 26;
//                 cout << "Remainder: " << rem << endl;
//                 if(rem != 0){
//                     curr = 96 + rem;    
//                 } else{
//                     curr = 122;
//                 }
//             }
//             cout << "After: " << curr << endl;
//             s[i] = static_cast<char>(curr);
//         }

//         return s;
//     }
// };

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long> currShifts(shifts.size(), shifts[shifts.size() - 1]);
        for(int i = currShifts.size() - 2; i >= 0; i--){
            currShifts[i] = shifts[i] + currShifts[i + 1];
        }

        for(int i = 0; i < currShifts.size(); i++){
            int asciVal = s[i] - 'a';
            long long curr = asciVal + 97 + currShifts[i];
            if(curr > 122){
                int rem = (curr - 96) % 26;
                if(rem != 0){
                    curr = 96 + rem;    
                } else{
                    curr = 122;
                }
            }
            s[i] = static_cast<char>(curr);
        }

        return s;
    }
};