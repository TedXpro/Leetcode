class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int answer = 0;
        unordered_set<int> memo(nums.begin(), nums.end());

        for(int currNum : nums){
            int currStreak = 0;

            long long currSquareNum = currNum;
            while(memo.find(currSquareNum) != memo.end()){
                currStreak++;
                if(currSquareNum * currSquareNum > 1e5){
                    break;
                }
                currSquareNum *= currSquareNum;
            }

            answer = max(answer, currStreak);
        }

        return answer >= 2 ? answer : -1;
    }
};