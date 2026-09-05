class Solution {
private:
    class rect {
    private:
        int index;
        int height;
    public:
        void setIndex(int ind){
            index = ind;
        } 
        void setHeight(int hei){
            height = hei;
        }
        int getIndex() {return index;}
        int getHeight() {return height;}

    };
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<rect> st;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int lastIndex = i;
            while(!st.empty() && st.top().getHeight() > heights[i]){
                int currArea = st.top().getHeight() * (i - st.top().getIndex());
                maxArea = max(currArea, maxArea);
                lastIndex = st.top().getIndex();
                st.pop();
            }
            rect newRect;
            newRect.setIndex(lastIndex);
            newRect.setHeight(heights[i]);
            st.push(newRect);
        }

        int i = heights.size();
        while(!st.empty()){
            int currArea = st.top().getHeight() * (i - st.top().getIndex());
            maxArea = max(currArea, maxArea);
            st.pop();
        }
        return maxArea;
    }
};