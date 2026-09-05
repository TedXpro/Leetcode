class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;
        for(vector<int>& q : queries){
            int curr = 0;
            for(int i = q[0]; i <= q[1]; i++){
                curr ^= arr[i];
            }

            answer.push_back(curr);
        }

        return answer;
    }
};