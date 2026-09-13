from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        deq = deque()
        answer = []

        for i in range(len(nums)):
            if deq and deq[0] <= i - k:
                deq.popleft()
            
            while deq and (nums[deq[-1]] < nums[i]):
                deq.pop()
            deq.append(i)
                
            if i >= k - 1:
                answer.append(nums[deq[0]])
                # print(nums[deq[0]])
                # print(answer)
        return answer