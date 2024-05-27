class Solution {
private:
    void merge(vector<int>& nums, int currStart, int currMid, int currEnd){
        vector<int> res(currEnd - currStart + 1, 0);
        int left = currStart, right = currMid + 1, index = 0;
        while(left <= currMid && right <= currEnd){
            res[index++] = nums[left] < nums[right] ? nums[left++] : nums[right++];
        }
         
        // leftovers
        while(left <= currMid){
            res[index++] = nums[left++];
        }

        while(right <= currEnd){
            res[index++] = nums[right++];
        }

        // copy result back to num
        for(int i = currStart; i <= currEnd; i++){
            nums[i] = res[i - currStart];
        }        
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start < end){
            int mid = start + (end - start) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};