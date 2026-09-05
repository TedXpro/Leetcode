class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> memo;
        int left = 0, right = 0;
        long long answer = 0;
        while(right < nums.size()){
            memo[nums[right]]++;
            while(memo.rbegin()->first - memo.begin()->first > 2){
                memo[nums[left]]--;
                if(memo[nums[left]] == 0){
                    memo.erase(nums[left]);
                }

                left++;
            }

            answer += (right - left + 1);
            right++;
        }

        return answer;
    }
};