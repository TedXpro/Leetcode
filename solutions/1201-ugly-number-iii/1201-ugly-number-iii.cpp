class Solution {
    int gcd(int a, int b){
        if(a % b == 0)
            return b;
        return gcd(b, a % b);
    }
public:    
   int nthUglyNumber(int k, int A, int B, int C) {
        
        int low = 1, high = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / gcd(a, b);
        long bc = b * c / gcd(b, c);
        long ac = a * c / gcd(a, c);
        long abc = a * bc / gcd(a, bc);
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            int curr = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
            if(curr < k) 
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};