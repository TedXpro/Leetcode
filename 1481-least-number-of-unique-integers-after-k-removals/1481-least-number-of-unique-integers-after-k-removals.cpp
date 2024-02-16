class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> memo;
        for(int num : arr)
            memo[num]++;
        
        vector<int> cache;
        for(auto m : memo)
            cache.push_back(m.second);
        
        sort(cache.begin(), cache.end());
        int index = 0;
        for(; index < cache.size(); index++){
            if(cache[index] > k)
                break;
            k -= cache[index];
        }

        return cache.size() - index;
    }
};