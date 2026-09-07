class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums) - 1
        seen = [0] * n
        for i in range(len(nums)):
            idx = nums[i] - 1
            if idx >= n:
                return False
            seen[idx] += 1
            
            limit = 2 if idx == n - 1 else 1
            if seen[idx] > limit:
                return False
            
            
        for i in range(n - 1):
            if seen[i] != 1:
                return False
        return True if seen[n - 1] == 2 else False