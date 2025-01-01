class Solution:
    def maxScore(self, s: str) -> int:
        right = 0
        for ch in s:
            if ch == '1':
                right += 1

        answer = 0
        left = 0
        for ch in s[:len(s) - 1]:
            if ch == '0':
                left += 1
            else:
                right -= 1
            answer = max(answer, left + right)
        
        return answer