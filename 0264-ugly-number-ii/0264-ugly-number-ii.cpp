class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies(n);
        uglies[0] = 1;
        int pt2 = 0, pt3 = 0, pt5 = 0;
        for(int i = 1; i < n; i++){
            int mini = min(uglies[pt2] * 2, min(uglies[pt3] * 3, uglies[pt5] * 5));
            while(uglies[pt2] * 2 == mini)
                pt2++;
            while(uglies[pt3] * 3 == mini)
                pt3++;
            while(uglies[pt5] * 5 == mini)
                pt5++;
            uglies[i] = mini;
        }

        return uglies[n - 1];
    }
};