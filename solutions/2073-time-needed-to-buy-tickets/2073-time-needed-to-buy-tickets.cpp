class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int answer = 0; 
        for(int i = 0; i < tickets.size(); i++){
            if( i <= k)
                answer += min(tickets[k], tickets[i]);
            else 
                answer += min(tickets[i], tickets[k] - 1);
        }

        return answer;
    }
};