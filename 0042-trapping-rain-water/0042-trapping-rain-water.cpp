class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right];
        int answer = 0;
        while(left <= right){
            if(leftMax < rightMax){
                answer += leftMax - height[left];
                left++;
                if(left < height.size())
                    leftMax = max(leftMax, height[left]);
            } else{
                answer += rightMax - height[right];
                right--;
                if(right >= 0)
                    rightMax =  max(rightMax, height[right]);
            }
        }

        return answer;
    }
};

