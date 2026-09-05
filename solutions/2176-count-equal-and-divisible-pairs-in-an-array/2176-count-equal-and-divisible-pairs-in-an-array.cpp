class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        // map<int, vector<int>> pairs;
        // int count = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     if(pairs.contains(nums[i])){
        //         for(int j = 0; j < pairs[nums[i]].size(); j++){
        //             if((i * pairs[nums[i]][j]) % k == 0)
        //                 count++;
        //         }
        //     }
        //     pairs[nums[i]].push_back(i);
        // }
        // return count;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if((nums[i] == nums[j]) && ((i * j) % k == 0))
                    count++;
            }
        }
        return count;
    }
};