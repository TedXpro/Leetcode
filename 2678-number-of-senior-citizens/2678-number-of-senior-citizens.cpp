class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        int len = 15;
        for(string& str : details){
            string s = str.substr(11,2);
            int num = stoi(s);
            cout << num << endl;
            if(num > 60){
                count++;
            }
        }
        return count;
    }
};