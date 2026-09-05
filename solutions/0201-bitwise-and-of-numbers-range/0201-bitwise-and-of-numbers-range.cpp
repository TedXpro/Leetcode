class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right)
            return left;
        int answer = left;
        int diff = right - left;
        for(int i = 0; i < 32; i++){
            if(diff >= pow(2, i))
                answer &= ~(1 << i);
            else 
                break;
        }

        return answer & right;
    }
};