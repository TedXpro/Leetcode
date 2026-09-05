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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> integerMatrix(matrix.size(), vector<int>(matrix[0].size()));
        for(int row = 0; row < matrix.size(); row++){
            for(int col = 0; col < matrix[row].size(); col++){
                if(row - 1 < 0 || matrix[row][col] == '0'){
                    integerMatrix[row][col] = matrix[row][col] - '0';
                    continue;
                }
                int prevNum = integerMatrix[row - 1][col];
                int currNum = matrix[row][col] - '0';
                integerMatrix[row][col] = currNum + prevNum;
            }
        }    
        int maxArea = 0;
        for(vector<int> & mat : integerMatrix){
            int currArea = largestRectangleArea(mat);
            maxArea = max(currArea, maxArea);
        }
        return maxArea;
    }
};