class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(string& log : logs){
            if(log == "../" && count > 0){
                count--;
            } else if(log != "./" && log != "../"){
                count++;
            }
        }
        return count;
    }
};