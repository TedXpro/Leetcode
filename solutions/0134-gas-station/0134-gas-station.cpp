class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0, costSum = 0;
        int index = 0;
        int totalSum = 0;
        for(int i = 0; i < gas.size(); i++){
            gasSum += gas[i];
            costSum += cost[i];
            totalSum += gas[i] - cost[i];
            if(totalSum < 0){
                totalSum = 0;
                index = i + 1;
            }    
        }   

        return gasSum >= costSum ? index : -1;
    }
};