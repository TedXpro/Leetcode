class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;  
            
            int target = -nums[i];
            for(int left = i + 1, right = nums.size() - 1; left < right;){
                int sum = nums[left] + nums[right];

                if(target == sum){
                    answer.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) 
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++;
                    right--;
                } else if(target < sum)
                    right--;
                else 
                    left++;
            }
        }
        return answer;
    }
};