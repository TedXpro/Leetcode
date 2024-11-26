class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int, int> memo;

        for(vector<int>& edge : edges){
            memo[edge[1]]++;
        }

        int answer = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(memo[i] == 0){
                answer = i;
                count++;
                if(count > 1){
                    return -1;
                }
            }
        }

        return answer;
    }
};