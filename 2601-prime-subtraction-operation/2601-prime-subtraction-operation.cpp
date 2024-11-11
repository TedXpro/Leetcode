class Solution {
    bool checkPrime(int num){
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0){
                return false;
            }
        }

        return true;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> prevPrime(maxEle + 1, 0);
        for(int i = 2; i <= maxEle; i++){
            if(checkPrime(i)){
                prevPrime[i] = i;
            } else {
                prevPrime[i] = prevPrime[i - 1];
            }
        }

        for(int i = 0; i < nums.size(); i++){
            int bound;
            if(i == 0){
                bound = nums[0];
            } else {
                bound = nums[i] - nums[i - 1];
            }

            if(bound <= 0){
                return false;
            }

            int largestPrime = prevPrime[bound - 1];
            nums[i] = nums[i] - largestPrime;
        }

        return true;
    }
};