class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> deg(n, 0);
        for(vector<int>& road : roads){
            deg[road[0]]++;
            deg[road[1]]++;
        }

        sort(deg.begin(), deg.end());
        long long answer = 0;
        int start = 1;
        for(long long d : deg){
            answer += start * d;
            start++;
        }
        return answer;
    }
};