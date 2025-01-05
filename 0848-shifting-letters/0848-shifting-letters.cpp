class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long> currShifts(shifts.size(), shifts[shifts.size() - 1]);
        for(int i = currShifts.size() - 2; i >= 0; i--){
            currShifts[i] = (shifts[i] + currShifts[i + 1]) % 26;
        }

        for(int i = 0; i < currShifts.size(); i++){
            s[i] = static_cast<char>((s[i] - 'a' + currShifts[i]) % 26 + 97);
        }

        return s;
    }
};