class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        int answer = 0;
        for(auto s : set1){
            for (auto s2 : set2){
                answer ^= (s ^ s2);
            }
        }

        return answer;
    }
};