class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand(time(0));
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> shuffledNums = nums;
        for(int i = nums.size() - 1; i >= 0; i--){
            int newIndex = rand() % (i + 1);
            swap(shuffledNums[newIndex], shuffledNums[i]);
        }
        return shuffledNums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */