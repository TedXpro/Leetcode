class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.begin() + 4);
        int a = nums[3];
        int b = nums[2];
        int c = nums[1];
        int d = nums[0];

        for(int i = 4; i < nums.size(); i++){
            if(nums[i] > a){
                b = a;
                a = nums[i];
            }
            else if(nums[i] > b)
                b = nums[i];
            else if(nums[i] < d){
                c = d;
                d = nums[i];
            }
            else if(nums[i] < c)
                c = nums[i];
        }
        return (a * b) - (c * d);

        // int a = 0, b = 0, c = INT_MAX, d = INT_MAX;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] > a){
        //         b = a; 
        //         a = nums[i];
        //     }
        //     else 
        //         b = max(nums[i], b);
        //     if(nums[i] < d){
        //         c = d;
        //         d = nums[i];
        //     }
        //     else 
        //         c = min(nums[i],c);
        // }
        // return (a * b) - (c * d);
    }    
};