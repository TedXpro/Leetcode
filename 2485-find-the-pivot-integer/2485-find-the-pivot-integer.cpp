class Solution {
public:
    int pivotInteger(int n) {
        int ans = sqrt((n * (n + 1)) / 2);
        return 2 * ans * ans == n * (n + 1)? ans : -1;
    }
};