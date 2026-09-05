class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int answer = 0;
        long long num = 1;
        int index = 0;

        while(num <= n){
            if(index < nums.size() && nums[index] <= num){
                num += nums[index];
                index++;
            } else {
                num += num;
                answer++;
            }
        }

        return answer;
    }
};