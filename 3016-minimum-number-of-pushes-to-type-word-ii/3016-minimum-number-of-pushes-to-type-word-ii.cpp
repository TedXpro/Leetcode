class Solution {
    static bool compareByValue(const pair<char, int>&a, const pair<char, int>&b){
        return a.second > b.second;
    }
public:
    int minimumPushes(string word) {
        unordered_map<char, int> memo;
        for(char ch : word){
            memo[ch]++;
        }

        vector<pair<char, int>> arr(memo.begin(), memo.end());
        sort(arr.begin(), arr.end(), compareByValue);

        int count = 1, by = 1, answer = 0;
        for(auto& val : arr){
            cout << val.first << " " << val.second << endl;
            if(count > 8){
                count = 1;
                by++;
            }
        
            answer += val.second * by;
            count++;
        }
        return answer;

    }
};