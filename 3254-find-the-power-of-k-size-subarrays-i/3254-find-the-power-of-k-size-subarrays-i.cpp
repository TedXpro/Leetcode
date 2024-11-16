class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> answer;
        int left = 0, count = 1;
        for(int right = 0; right < nums.size(); right++){
            if(right > 0 && nums[right - 1] + 1 == nums[right]){
                count++;
            }

            if(right - left + 1 > k){
                if(nums[left] + 1 == nums[left + 1]){
                    count--;
                }
                left++;
            }

            if(right - left + 1 == k){
                answer.push_back(count == k ? nums[right] : -1);
            }
        }

        return answer;
    }
};