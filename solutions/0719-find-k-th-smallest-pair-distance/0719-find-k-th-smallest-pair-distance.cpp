class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maxEle = *max_element(nums.begin(), nums.end());
        vector<int> dist(maxEle + 1, 0);

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int d = abs(nums[i] - nums[j]);
                dist[d]++;
            }
        }

        for(int d = 0; d <= maxEle; d++){
            k -= dist[d];
            if(k <= 0){
                return d;
            }
        }

        return -1;
    }
};