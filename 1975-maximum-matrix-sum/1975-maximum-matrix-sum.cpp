class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long answer = 0;
        int minNum = INT_MAX;
        int count = 0;
        for(vector<int>& mat : matrix){
            for(int m : mat){
                answer += abs(m);
                minNum = min(minNum, abs(m));
                if(m < 0){
                    cout << m << endl;
                    count++;
                }
            }
        }

        cout << "min: " << minNum << " answer: " << answer << endl;
        return count % 2 == 0 ? answer : answer - (2 * minNum);
    }
};