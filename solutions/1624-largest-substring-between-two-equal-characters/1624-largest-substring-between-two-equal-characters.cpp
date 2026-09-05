class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> indices;
        int maxSize = -1;
        for(int i = 0; i < s.length(); i++){
            if(indices.contains(s[i]))
                maxSize = max(maxSize, i - indices[s[i]] - 1);
            else 
                indices[s[i]] = i;
        }
        return maxSize;
    }
};