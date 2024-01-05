class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count = 0;
        int maxIndex = 0;
        for(int i = 0; i < flips.size(); i++){
            maxIndex = max(maxIndex, flips[i]);
            if(maxIndex == i + 1)
                count++;
        }
        return count;
    }
};