class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int> memo;
        memo[0] = 1;
        int mask = 0;
        long answer = 0;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            int bit = ch - 'a';
            mask ^= (1 << bit);
            answer += memo[mask];
            memo[mask]++;

            for(int j = 0; j < 10; j++)
                answer += memo[mask ^ (1 << j)];
        }

        return answer;
    }
};