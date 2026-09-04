class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)

        m, n = len(nums1), len(nums2)
        tot = (m + n + 1) // 2

        low, high = 0, m
        while low <= high:
            start = (low + high) // 2
            end = tot - start

            nums1L = nums1[start - 1] if start > 0 else float('-inf')
            nums1R = nums1[start] if start  < m else float('inf')
            
            nums2L = nums2[end - 1] if end > 0 else float('-inf') 
            nums2R = nums2[end] if end < n else float('inf')
            
            if ((nums1L <= nums2R) and (nums2L <= nums1R)):
                if(m + n) % 2 == 1:
                    return float(max(nums1L, nums2L))
                return (max(nums1L, nums2L) + min(nums1R, nums2R)) / 2
            
            elif nums1L > nums2R:
                high = start - 1
            else:
                low = start + 1