class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int current = 0, next = 1, winCount = 0; 
        while(winCount < k && next < arr.size()){
            if(arr[current] < arr[next]){
                winCount = 0;
                current = next;
            }   
            next++;
            winCount++;
        }
        return arr[current];
    }
};