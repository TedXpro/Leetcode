class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() == 1)
            return false;
        bool inc = true;
        for(int i = 1; i < arr.size(); i++){
            if(inc){
                if(i == 1 && arr[i - 1] > arr[i])
                    return false;
                if(arr[i - 1] > arr[i]) 
                    inc = false;
                if(arr[i - 1] == arr[i])
                    return false;
            }
            else {
                if(arr[i - 1] < arr[i])
                    return false;
                if(arr[i - 1] == arr[i])
                    return false;
            }
        }
        return inc ? false : true;
    }
};