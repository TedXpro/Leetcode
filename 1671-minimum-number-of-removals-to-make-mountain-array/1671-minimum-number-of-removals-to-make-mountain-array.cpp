class Solution {
private:
    vector<int> getLis(vector<int>& nums){
        vector<int> lisLen(nums.size(), 1);
        vector<int> lis = {nums[0]};
        for(int i = 1; i < nums.size(); i++){
            int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

            if(index == lis.size()){
                lis.push_back(nums[i]);
            } else {
                lis[index] = nums[i];
            }
            lisLen[i] = lis.size();
        }

        return lisLen;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size();
        vector<int> lisLength = getLis(nums);

        reverse(nums.begin(), nums.end());
        vector<int> ldsLength = getLis(nums);

        reverse(ldsLength.begin(), ldsLength.end());

        int answer = INT_MAX;
        for(int i = 0; i < size; i++){
            if(lisLength[i] > 1 && ldsLength[i] > 1){
                answer = min(answer, size - lisLength[i] - ldsLength[i] + 1);
            }
        }

        return answer;
    }
};