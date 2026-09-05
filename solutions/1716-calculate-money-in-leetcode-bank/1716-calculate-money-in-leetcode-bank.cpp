class Solution {
public:
    int totalMoney(int n) {
        int monday = 0;
        int j = 0;
        int total = 0;
        for(int i = 0; i < n; i++){
            if(i % 7 == 0){
                monday++;
                total += monday;
                j = 1;
                continue;
            }
            total += (monday + j);
            j++;
        }
        return total;


        // int remDays = n / 7;
        // int firstWeekTotal = 28;
        // int lastWeekTotal = firstWeekTotal + (remDays - 1) * 7;
        // int totalSum = remDays * (firstWeekTotal + lastWeekTotal) / 2;

        // int monday = 1 + remDays;
        // int finalWeek = 0;
        // for(int day = 0; day < n % 7; day++)
        //     finalWeek += monday + day;
        
        // return finalWeek + totalSum;
    }
};