class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, int> memo;
        int index = 0;
        for(int height : heights){
            memo[height] = index;
            index++;
        }

        sort(heights.begin(), heights.end());
        vector<string> answer;
        for(int i = heights.size() - 1; i >= 0; i--){
            answer.push_back(names[memo[heights[i]]]);
        }

        return answer;

    }
};