class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> memo;
        unordered_set<string> removed;
        for(string& str : arr){
            if(removed.find(str) == removed.end() && memo.find(str) == memo.end()){
                memo.insert(str);
            } else {
                memo.erase(str);
                removed.insert(str);
            }
        }
        
        if(memo.size() < k){
            return "";
        }
        int curr = 0;
        for(string& str : arr){
            if(memo.find(str) != memo.end()){
                curr++;
                if(curr == k){
                    return str;
                }
            }
        }
        return "";
    }
};