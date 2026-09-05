class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFrequency = 0;
        unordered_map<int, int>memo;
        for(int num : nums){
            memo[num]++;
            if(memo[num] > maxFrequency)
                maxFrequency = memo[num];
        }

        int answer = 0;
        for(auto& m : memo){
            if(m.second == maxFrequency)
                answer += maxFrequency;
        }

        return answer;
    }
};