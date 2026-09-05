class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0)
            return false;
        map<int, int> memo;
        for(int num : nums)
            memo[num]++;
        
        while(!memo.empty()){
            int curr = memo.begin()->first;
            for(int i = 0; i < k; i++){
                if(memo[curr + i] == 0)
                    return false;
                memo[curr + i]--;
                if(memo[curr + i] < 1)
                    memo.erase(curr + i);
            }
        }

        return true;
    }
};