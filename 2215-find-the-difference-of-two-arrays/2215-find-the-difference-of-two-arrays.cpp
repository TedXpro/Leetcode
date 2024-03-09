class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> memo1;
        unordered_set<int> memo2;
        for(int num : nums1)
            memo1.insert(num);
        
        vector<vector<int>> answer(2);
        unordered_set<int> seen;
        for(int num : nums2){
            memo2.insert(num);
            if(memo1.find(num) == memo1.end()){
                if(seen.find(num) == seen.end()){
                    answer[1].push_back(num);
                    seen.insert(num);
                }
            }
        }
        
        for(int num : nums1){
            if(memo2.find(num) == memo2.end()){
                if(seen.find(num) == seen.end()){
                    answer[0].push_back(num);
                    seen.insert(num);
                }
            }
        }
        
        return answer;
    }
};