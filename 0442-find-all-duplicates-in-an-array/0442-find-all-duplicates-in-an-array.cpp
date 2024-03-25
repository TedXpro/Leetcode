class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> answer;
        for(int index = 0; index < nums.size(); index++){
            if(nums[index] == -1)
                continue;
            int currIndex = nums[index];
            nums[index] = 0;
            bool flag = false;
            while(nums[currIndex - 1] != -1 && currIndex - 1 != index){
                int num = nums[currIndex - 1];
                nums[currIndex - 1] = -1;
                if(num == 0){
                    flag = true;
                    break;
                }
                currIndex = num;
            }
            if(flag)
                continue;
            if(currIndex - 1 == index)
                nums[currIndex - 1] = -1;
            else 
                answer.push_back(currIndex);
            
        }

        return answer;
    }
};