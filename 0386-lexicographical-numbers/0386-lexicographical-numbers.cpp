class Solution {
    void dfs(vector<int>& answer, int curr, int limit){
        if(curr > limit){
            return;
        }
        answer.push_back(curr);
        for(int i = 0; i <= 9; i++){
            int next = curr * 10 + i;
            if(next > limit){
                break;
            }
            dfs(answer, next, limit);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        for(int curr = 1; curr <= 9; curr++){
            dfs(answer, curr, n);
        }
        
        return answer;
    }
};