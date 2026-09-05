class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> memo;
        for(int num : nums){
            if(memo.find(num) != memo.end())
                return true;
            memo.insert(num);
        }

        return false;
    }
};