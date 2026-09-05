class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
            return 0;
        
        int index = 0;
        int curr = 1;
        while(curr * 2 <= n){
            curr *= 2;
            index++;
        }

        return (1 << (index + 1)) - 1 - minimumOneBitOperations(n ^ curr);
    }
};