class Solution {
    vector<int> findIntersection(vector<int> &larger, vector<int>& smaller){
        unordered_map<int, int> memo;
        vector<int> answer;
        for(int num : larger)
            memo[num]++;

        for(int num : smaller){
            if(memo.find(num) != memo.end() && memo[num] > 0){
                memo[num]--;
                answer.push_back(num);
            }
        }

        return answer;
    }
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() >= nums2.size()){
            return findIntersection(nums1, nums2);            
        }

        return findIntersection(nums2, nums1);
    }
};