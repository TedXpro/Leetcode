class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = numBottles;
        while(numBottles / numExchange != 0){
            int quo = numBottles / numExchange;
            answer += quo;
            numBottles -= quo * numExchange;
            numBottles += quo;
        }

        return answer;
    }
};