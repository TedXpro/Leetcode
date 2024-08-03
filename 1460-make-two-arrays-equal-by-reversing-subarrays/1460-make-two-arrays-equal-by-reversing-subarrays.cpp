class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> memo;
        for(int num : target){
            memo[num]++;
        }

        for(int num : arr){
            if(memo.find(num) == memo.end()){
                return false;
            }
            memo[num]--;
            if(memo[num] == 0) {
                memo.erase(num);
            }
        }

        if(memo.size() > 0){
            return false;
        }

        return true;

    }
};