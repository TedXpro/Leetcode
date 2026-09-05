class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int start = customers[0][0];
        int currTime = customers[0][0];
        double answer = 0;

        for(vector<int>& cust : customers){
            start = cust[0];
            
            if(currTime < cust[0]){
                currTime = cust[0] + cust[1];
                answer += (currTime - start);
            } else{
                currTime += cust[1];
                answer += (currTime - start);
            }
        }

        cout << answer << endl;
        return answer / customers.size();
    }
};