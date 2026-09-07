class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        nums.append(0)
        stack = []
        max_score = 0
        for i in range(len(nums)):
            while stack and nums[i] < nums[stack[-1]]:
                h = stack.pop()
                left = stack[-1] + 1 if stack else 0
                right = i - 1

                if left <= k and k <= right:
                    width = right - left + 1
                    score = nums[h] * width
                    max_score = max(max_score, score)

            stack.append(i)

        return max_score