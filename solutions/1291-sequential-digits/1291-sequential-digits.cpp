class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        int start = to_string(low).length();
        int end = to_string(high).length();

        const string DIGITS = "123456789";

        for(int index = start; index <= end; index++){
            for(int position = 0; position <= 9 - index; position++){
                string str = DIGITS.substr(position, index);
                int currNum = stoi(str);

                if(currNum >= low && currNum <= high)
                    answer.push_back(currNum);
            }
        } 

        return answer;
    }
};