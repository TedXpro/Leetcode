class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int index = 1;
        for(; index <= citations.size(); index++){
            if(citations[citations.size() - index] < index){
                break;
            }
        }

        return index - 1;
    }
};