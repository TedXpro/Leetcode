class Solution {
    int findMinimum(string &ring, string &key, int ringIndex, int keyIndex, unordered_map<string, int> &memo){
        if(keyIndex == key.length())
            return 0;
        string mapKey = to_string(ringIndex) + "," +  to_string(keyIndex);
        if(memo.find(mapKey) != memo.end())
            return memo[mapKey];

        int answer = INT_MAX;
        for(int i = 0; i < ring.length(); i++){
            if(ring[i] == key[keyIndex]){
                int diff = abs(ringIndex - i);
                int revDiff = ring.length() - diff;
                int currRes = min(revDiff, diff);
                currRes = currRes + 1 + findMinimum(ring, key, i, keyIndex + 1, memo);
                answer = min(answer, currRes);
            }
        }

        memo[mapKey] = answer;
        return answer;
    }
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<string, int> memo;
        return findMinimum(ring, key, 0, 0, memo);
    }
};