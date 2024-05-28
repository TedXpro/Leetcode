class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int answer = 0;
        int currCost = 0;
        int index = 0;
        for(int i = 0; i < s.size(); i++){
            currCost += abs(s[i] - t[i]);

            while(currCost > maxCost){
                currCost -= abs(s[index] - t[index]);
                index++;
            }
            answer = max(answer, i - index + 1);
        }

        return answer;
    }
};