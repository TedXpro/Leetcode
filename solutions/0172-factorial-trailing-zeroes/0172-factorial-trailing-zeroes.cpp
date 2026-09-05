class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for(int i = 1; i < n; i++){
            int curr = n / pow(5, i);
            if(curr == 0){
                break;
            }
            count += curr;
        }

        return count;
    }
};