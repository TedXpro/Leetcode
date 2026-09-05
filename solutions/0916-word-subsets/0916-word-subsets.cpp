class Solution {
private:
    vector<int> count(const string& S) {
        vector<int> ans(26, 0); // Initialize with 0s
        for (char c : S) {
            ans[c - 'a']++;
        }
        return ans;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bmax(26, 0); // Initialize with 0s
        for (const string& b : words2) {
            vector<int> bCount = count(b);
            for (int i = 0; i < 26; ++i) {
                bmax[i] = max(bmax[i], bCount[i]);
            }
        }

        vector<string> ans;
        for (const string& a : words1) {
            vector<int> aCount = count(a);
            bool isSubset = true; 
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    isSubset = false;
                    break; // Exit the inner loop if not a subset
                }
            }
            if (isSubset) {
                ans.push_back(a);
            }
        }

        return ans;
    }
};