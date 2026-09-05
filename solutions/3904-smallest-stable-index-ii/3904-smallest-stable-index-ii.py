class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        min_array = [0] * len(nums)
        smallest = float('inf')
        for i in range(len(nums) - 1, -1, -1):
            smallest = min(smallest, nums[i])
            min_array[i] = smallest

        largest = -1
        for i in range(len(nums)):
            largest = max(largest, nums[i])
            temp = largest - min_array[i]
            if temp <= k:
                return i
        
        return -1
