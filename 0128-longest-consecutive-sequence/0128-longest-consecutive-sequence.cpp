class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int maxLength = 0;
        for(int num : numbers){
            if(numbers.find(num - 1) != numbers.end())
                continue;
            else {  // its a start to a sequence!
                int count = 1;
                int n = num;
                while(numbers.find(n + 1) != numbers.end()){
                    n++;
                    count++;
                }

                maxLength = max(maxLength, count);
            }
        }

        return maxLength;
    }
};