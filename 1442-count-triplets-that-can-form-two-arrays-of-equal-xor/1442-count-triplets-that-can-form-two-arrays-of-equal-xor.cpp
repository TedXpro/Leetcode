class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int pre = 0;
        unordered_map<int, int> countMap = {{0,1}}, total;

        for(int i = 0; i < arr.size(); i++){
            pre ^= arr[i];

            count += countMap[pre]++ * i - total[pre];

            total[pre] += i + 1;
        }

        return count;
    }
};