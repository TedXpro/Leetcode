class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> memo;
        for(int i = 0; i < nums.size(); i++)
            memo[nums[i]] = i;
        
        for(int i = 0; i < operations.size(); i++){
            if(memo.contains(operations[i][0])){
                nums[memo[operations[i][0]]] = operations[i][1];
                auto nodeHandler = memo.extract(operations[i][0]);
                nodeHandler.key() = operations[i][1];
                memo.insert(move(nodeHandler));
            }
        }
        return nums;
    }
};