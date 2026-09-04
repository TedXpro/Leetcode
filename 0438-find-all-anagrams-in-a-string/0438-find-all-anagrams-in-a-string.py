class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        substring_count = [0] * 26
        p_count = [0] * 26
        for i in range(len(p)):
            p_count[ord(p[i]) - ord('a')] += 1
            substring_count[ord(s[i]) - ord('a')] += 1
        
        answer = list()
        
        left = 0
        right = len(p) - 1
        while right < len(s):
            if substring_count == p_count:
                answer.append(left)
            
            substring_count[ord(s[left]) - ord('a')] -= 1
            left += 1
            right += 1
            if right < len(s):
                substring_count[ord(s[right]) - ord('a')] += 1
        return answer