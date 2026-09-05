class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> preMax = arr;
        vector<int> sufMin = arr;
        for(int i = 1; i < arr.size(); i++){
            preMax[i] = max(preMax[i - 1], preMax[i]);
        }

        for(int i = arr.size() - 2; i >= 0; i--){
            sufMin[i] = min(sufMin[i], sufMin[i + 1]);
        }

        int answer = 0;
        for(int i = 0; i < arr.size(); i++){
            if(i == 0 || preMax[i - 1] < sufMin[i]){
                answer++;
            }
        }

        return answer;
    }
};