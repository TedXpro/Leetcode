class Solution {
public:
    int jump(vector<int>& nums) {
        int answer = 0; 
        int left = 0, right = 0;
        while(right < nums.size() - 1){
            int maxDist = right;
            for(int i = left; i < right + 1; i++){
                maxDist = max(maxDist, i + nums[i]);
            }
            left = right + 1;
            right = maxDist;
            answer++;
        }

        return answer;
    }
};