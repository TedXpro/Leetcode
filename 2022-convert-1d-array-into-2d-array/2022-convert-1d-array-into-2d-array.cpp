class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m == 1 && n == 1 && original.size() != 1){
return {};}
        if(m * n != original.size()){
return {};
}
        vector<vector<int>> answer;
        int curr = 0;
        vector <int> currVec;
        for(int num : original){
            if (curr == n){
                answer.push_back(currVec);
               currVec.clear();
                curr = 0;
            }
            currVec.push_back(num);
            curr++;
        }
                        answer.push_back(currVec);
        return answer;
    }
};