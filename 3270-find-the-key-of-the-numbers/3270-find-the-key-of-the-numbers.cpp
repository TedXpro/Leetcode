class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string n1 = to_string(num1);
        while(n1.length() < 4){
            n1 = '0' + n1;
        }
        string n2 = to_string(num2);
        while(n2.length() < 4){
            n2 = '0' + n2;
        }
        string n3 = to_string(num3);
        while(n3.length() < 4){
            n3 = '0' + n3;
        }
        
        int answer = 0;
        for(int i = 0; i < 4; i++){
            int x = n1[i] - '0';
            int y = n2[i] - '0';
            int z = n3[i] - '0';

            answer *= 10;
            answer += min(x, min(y, z));
        }

        return answer;
    }
};