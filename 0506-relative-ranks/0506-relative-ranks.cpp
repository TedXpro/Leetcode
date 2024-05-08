class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> arr = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        int index = 0;
        vector<string> answer(score.size(), "");
        unordered_map<int, int> memo;
        for(int i = 0; i < score.size(); i++)
            memo[score[i]] = i;
        
        sort(score.begin(), score.end(), greater<int>());
        for(int i = 0; i < score.size(); i++){
            if(i < 3)
                answer[memo[score[i]]] = arr[index];
            else 
                answer[memo[score[i]]] = to_string(index + 1);
            index++;
        }
        return answer;
    }
};