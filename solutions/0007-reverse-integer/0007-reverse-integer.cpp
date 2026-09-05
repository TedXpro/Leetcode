class Solution {
public:
    int reverse(int x) {
        string num = to_string(x);
        bool negative = false;
        if(x < 0)
            negative = true;
        ::reverse(num.begin(), num.end());
        x = stoi(num);
        if(negative)
            x *= -1;
        return x;
    }
};