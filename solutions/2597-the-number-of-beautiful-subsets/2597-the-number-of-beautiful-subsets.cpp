class Solution {
    void findSubsets(vector<int>&nums, vector<int> curr, int index, int& k,  int &answer){
        if(index == nums.size()){
            if(checkSubsets(curr, k))
                answer++;
            return;
        }

        curr.push_back(nums[index]);
        findSubsets(nums, curr, index + 1, k, answer);
        curr.pop_back();
        findSubsets(nums, curr, index + 1, k, answer);
    }   

    bool checkSubsets(vector<int> &curr, int k){
        unordered_set<int> memo;
        for(int num : curr){
            if(memo.find(num) != memo.end())
                return false;
            memo.insert(num + k);
            // memo.insert(num - k);
        }
        memo.clear();

        return true;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int answer = 0;
        sort(nums.begin(), nums.end());
        findSubsets(nums, vector<int> {}, 0, k, answer);
        return answer - 1;
    }
};