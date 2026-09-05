class Solution {
public:
    long long minEnd(int n, int x) {
        if(n == 1){
            return x;
        }
        long long curr = (x + 1) | x;
        for(int i = 1; i < n - 1; i++){
            curr = (curr + 1) | x;
        }

        return curr;
    }
};