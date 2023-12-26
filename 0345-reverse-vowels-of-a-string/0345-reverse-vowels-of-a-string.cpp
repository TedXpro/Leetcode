class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a', 'e', 'i', 'o','u'};
        vector<int> indices;
        for(int i = 0; i < s.length(); i++){
            if(vowels.find(tolower(s[i])) != vowels.end()){
                indices.push_back(i);
            }
        }

        for(int start = 0, end = indices.size() - 1; start <  end; start++, end--){
            swap(s[indices[start]], s[indices[end]]);
        }
        return s;
    }
};