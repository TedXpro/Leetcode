class Solution {
public:
    int maximumSwap(int num) {
        vector<int> occur(10,0);
        vector<int> latestIndex(10,0);
        string strNum = to_string(num);
        for(int i = 0; i < strNum.length(); i++){
            occur[strNum[i] - '0']++;
            latestIndex[strNum[i] - '0'] = i;
        }

        int index = 9;

        for(int i = 0; i < strNum.length(); i++){
            cout << strNum[i] << " index " << index << endl;
            while(occur[index] == 0){
                index--;
            }
            if(strNum[i] - '0' < index){
                char ch = strNum[i];
                strNum[i] = index + '0';
                strNum[latestIndex[index]] = ch;
                cout << ch << " : " << index << " : " << strNum << endl;
                break;
            } else if(strNum[i] - '0' == index){
                if(occur[index] == 1){
                    index--;
                } else {
                    occur[index]--;
                }
            }
        }

        return stoi(strNum);
    }
};