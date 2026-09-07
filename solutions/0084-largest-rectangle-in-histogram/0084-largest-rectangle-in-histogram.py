class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        stack = []
        max_area = 0
        for i in range(len(heights)):
            while stack and heights[i] < heights[stack[-1]]:
                h = stack.pop()
                width = i
                if stack:
                    width = width - stack[-1] - 1
                area = heights[h] * width
                max_area = max(max_area, area)
            stack.append(i)
        return max_area