class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> memo;
        for(int i = 0; i < s.length(); i++){
            if(memo.find(s[i]) != memo.end()){
                memo[s[i]] = i - memo[s[i]] - 1;
            } else {
                memo[s[i]] = i;
            }
        }

        for(int i = 0; i < distance.size(); i++){
            char curr = static_cast<char>(i + 'a');
            cout << curr << endl;
            if(memo.find(curr) != memo.end()){
                if(distance[i] != memo[curr]){
                    return false;
                }
            }
        }

        return true;
    }
};