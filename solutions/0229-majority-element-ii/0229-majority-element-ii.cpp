class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> occurrence;
        for(int num : nums)
            occurrence[num]++;
        
        vector<int> answer;
        for(pair<int, int> occur : occurrence){
            if(occur.second > nums.size() / 3)
                answer.push_back(occur.first);
        }
        return answer;
    }
};