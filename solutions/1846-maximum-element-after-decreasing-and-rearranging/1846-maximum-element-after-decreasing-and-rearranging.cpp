class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int size = arr.size();
        vector<int> freq = vector(size + 1, 0);
        for(int num : arr)
            freq[min(num, size)]++;

        int max = 1;
        for(int num = 2; num <= size; num++)
            max = min(max + freq[num], num);

        return max;
    }
};