class Solution {
    // int count(string str){
    //     int counter = 0;
    //     for(char ch : str){
    //         if(ch == '1')
    //             counter++; 
    //     }
    //     return counter;
    // }
public:
    int numberOfBeams(vector<string>& bank) {
        int currCounter = 0;
        int answer = 0;
        for(int row = 0; row < bank.size(); row++){
            // int c = count(bank[row]);
            int c = 0;
            for(char ch : bank[row]){
                if(ch == '1')
                    c++;
            }
            if(c != 0){
                answer += currCounter * c;
                currCounter = c;
            }
        }
        return answer;
    }
};