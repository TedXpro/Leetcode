class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // vector<int> leftSubarray;
        // vector<int> rightSubarray;
        // int equals = 0;

        // for(int num : nums){
        //     if(num > pivot)
        //         rightSubarray.push_back(num);
        //     else if (num < pivot)
        //         leftSubarray.push_back(num);
        //     else 
        //         equals++;
        // } 
        
        // vector<int> answer;
        // for(int left : leftSubarray)
        //     answer.push_back(left);

        // for(equals; equals > 0; equals--)
        //     answer.push_back(pivot);
        
        // for(int right : rightSubarray)
        //     answer.push_back(right);
            
        // return answer;

        vector<int> answer(nums.size());
        int start = 0, end = nums.size() - 1, i = 0, j = nums.size() - 1;
        while(i < nums.size()){
            if(nums[i] < pivot)
                answer[start++] = nums[i];
            
            if(nums[j] > pivot)
                answer[end--] = nums[j];
            i++;
            j--;
        }

        while(start <= end)
            answer[start++] = pivot;
            
        return answer;
    }
};