class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n <= 2)
            return 1;
        int first = 1;
        int second = 1;
        int third = 0;

        while(n >= 3){
            int temp = first;
            first = first + second + third;
            third = second;
            second = temp;
            n--;
        }

        return first;
    }
};