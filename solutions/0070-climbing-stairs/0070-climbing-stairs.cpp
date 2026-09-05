class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int firstN = 1;
        int secondN = 2;
        for(int i = 3; i <= n; i++)
        {
            int temp = secondN;
            secondN += firstN;
            firstN = temp;
        }
        return secondN;
    }
};