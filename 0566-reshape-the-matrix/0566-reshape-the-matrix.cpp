class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r * c != mat.size() * mat[0].size()){
            return mat;
        }

        int curr = 0; 
        vector<vector<int>> answer;
        vector<int> currAns;
        for(vector<int>& currMat : mat){
            for(int num : currMat){
                currAns.push_back(num);
                curr++;
                if(curr == c){
                    answer.push_back(currAns);
                    currAns.clear();
                    curr = 0;
                }
                
            }
        }
        return answer;
    }
};