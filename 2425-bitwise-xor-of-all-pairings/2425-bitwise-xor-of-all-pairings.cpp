class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, long> memo;
        for(int num : nums1){
            memo[num] += nums2.size();
        }

        for(int num : nums2){
            memo[num] += nums1.size();
        }

        int answer = 0;
        for(auto m : memo){
            if(m.second % 2 == 1){
                answer ^= m.first;
            }
        }

        return answer;
    }
};