class Solution {
private:
    static bool comparator(pair<char, int>& v1, pair<char, int>& v2) {
        return v1.second > v2.second;
    }

public:
    string frequencySort(string s) {
        unordered_map<char, int> memo;
        for (char ch : s)
            memo[ch]++;

        vector<pair<char, int>> cache(memo.begin(), memo.end());
        sort(cache.begin(), cache.end(), comparator);

        string result = "";
        for (auto& it : cache) {
            result += string(it.second, it.first);
        }

        return result;
    }
};