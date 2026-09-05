class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int number = 0;
        for(int num : nums)
            number ^= num;
        number ^= k;
        int answer = 0;
        while(number > 0){
            answer += number % 2;
            number /= 2;
        }

        return answer;
    }
};