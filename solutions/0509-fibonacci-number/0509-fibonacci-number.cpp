/* Top Down approach memoization */
// class Solution {
// private:
//     unordered_map<int, int> memo;
//     int findFib(int n){
//         if(n == 0)
//             return 0;
//         if(n <= 2)
//             return 1;
//         if(memo.find(n) != memo.end())
//             return memo[n];
//         int result = findFib(n - 1) + findFib(n - 2);
//         memo[n] = result;
//         return result;
//     }
// public:
//     int fib(int n) {
//         return findFib(n);
//     }
// };

/* Bottom Up approach */
class Solution{
public:
    int fib(int n) {
        if(n <= 1)
            return n;

        int second = 0;
        int first = 1;
        for(int i = 1; i < n; i++){
            int temp = first + second;
            second = first;
            first = temp;
        }

        return first;
    }
};