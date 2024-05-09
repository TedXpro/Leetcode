class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long answer = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        int decreament = 0;
        for(int hap : happiness){
            answer += max(0, hap - decreament);
            decreament++;
            if(--k == 0)
                break;
        }
        return answer;
    }
};