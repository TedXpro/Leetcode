class Solution {
    void merge(vector<int> &nums, int start, int mid, int end){
        int left = start;
        int right = mid + 1;

        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                left++;
            } else {
                int value = nums[right];
                int index = right;

                while (index > left) {
                    nums[index] = nums[index - 1];
                    index--;
                }
                nums[left] = value;

                left++;
                mid++;
                right++;
            }
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
    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        // return nums;
    }
};