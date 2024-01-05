class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /* This has a time complexity of O(n^2) and a space complexity of O(n) */
        // vector<int> lis(nums.size(), 1);

        // for(int i = nums.size() - 1; i >= 0; i--){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         if(nums[j] > nums[i])
        //             lis[i] = max(lis[i], 1 + lis[j]);
        //     }
        // }
        // int maximum = 0;
        // for(int l : lis)
        //     maximum = max(maximum, l);
        // return maximum;

        /* has a time complexity of O(nlogn) and a space complexity og O(n)*/
        vector<int> lis;
        lis.push_back(nums[0]);
        int count = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > lis[count - 1]){
                lis.push_back(nums[i]);
                count++;
            }
            else {
                int itr = count - 1;
                while (itr >= 0 && lis[itr] >= nums[i])
                    itr--;
                lis[itr + 1] = nums[i];
            }
        }
        return count;
    }
};