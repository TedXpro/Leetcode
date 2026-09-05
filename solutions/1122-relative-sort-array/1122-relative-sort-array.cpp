class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> dontAppear;
        unordered_set<int> distinct;
        unordered_map<int, int> memo;

        for(int arr : arr2)
            distinct.insert(arr);
        
        for(int arr : arr1){
            if(distinct.find(arr) == distinct.end())
                dontAppear.push_back(arr);
            else
                memo[arr]++;
        }

        sort(dontAppear.begin(), dontAppear.end());
        int index = 0;
        for(int dis : arr2){
            for(int j = 0; j < memo[dis]; j++){
                arr1[index] = dis;
                index++;
            }
        }

        for(int i = 0; i < dontAppear.size(); i++){
            arr1[index] = dontAppear[i];
            index++;
        }

        return arr1;
    }
};