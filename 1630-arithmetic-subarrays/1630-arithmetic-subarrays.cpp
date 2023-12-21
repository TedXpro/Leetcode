class Solution {
    bool checkSubarray(vector<int> array){
        //using hashset and checking if minimum + diff is in the hashset.

        // int minimum = INT_MAX;
        // int maximum = INT_MIN;
        // unordered_set<int> arrSet;

        // for(int num : array){
        //     minimum = min(minimum, num);
        //     maximum = max(maximum, num);
        //     arrSet.insert(num);
        // }

        // if(((maximum - minimum) % (array.size() - 1)) != 0)
        //     return false;
        
        // int diff = (maximum - minimum) / (array.size() - 1);
        // int curr = minimum + diff;

        // while(curr < maximum){
        //     if(arrSet.find(curr) == arrSet.end())
        //         return false;
            
        //     curr += diff;
        // }

        // return true;

        // sorting and then checking every element.
        sort(array.begin(), array.end());
        int diff = array[1] - array[0];
        for(int i = 1; i < array.size() - 1; i++){
            if(array[i + 1] - array[i] != diff)
                return false;
        }
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> answer;
        for(int i = 0; i < l.size(); i++){
            answer.push_back(checkSubarray(vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1)));
        }
        return answer;
    }
};