class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> memo;
        for(int num : nums1)
                memo.insert(num);
        unordered_set<int> answer;
        for(int num : nums2){
            if(memo.find(num) != memo.end())
                answer.insert(num);
        }
        
        return vector<int>(answer.begin(), answer.end());
    }
};