class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> memo;
        for(int num : arr){
            if(memo.find(num * 2) != memo.end() || (num % 2 == 0 && memo.find(num / 2) != memo.end())){
                return true;
            }

            memo.insert(num);
        }

        return false;
    }
};