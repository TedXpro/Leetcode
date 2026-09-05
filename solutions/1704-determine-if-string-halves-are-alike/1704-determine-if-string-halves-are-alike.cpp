class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int firstCounter = 0;
        int secondCounter = 0;

        unordered_set<char> vowels {'a','e','i','o','u','A','E','I','O','U'};
        for(int first = 0, second = n / 2; first < n / 2 && second < n; first++, second++){
            if(vowels.find(s[first]) != vowels.end())
                firstCounter++;
            if(vowels.find(s[second]) != vowels.end())
                secondCounter++;
        }

        return firstCounter == secondCounter;
    }
};