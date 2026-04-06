"""Find the longest consecutive sequence in an array of integers.

This module contains a solution for finding the length of the longest consecutive
sequence that can be formed from an array of integers, running in O(n) time.
"""

from typing import List


class Solution:
    """Solution class for finding longest consecutive sequence."""
    
    def longestConsecutive(self, nums: List[int]) -> int:
        """Find the length of the longest consecutive sequence.
        
        A consecutive sequence is a sequence of elements in which each element 
        is exactly 1 greater than the previous element. The elements do not 
        have to be consecutive in the original array.
        
        Args:
            nums: List of integers to search for consecutive sequences.
            
        Returns:
            The length of the longest consecutive sequence that can be formed.
            
        Example:
            >>> solution = Solution()
            >>> solution.longestConsecutive([100, 4, 200, 1, 3, 2])
            4
        """
        # O(n) time, O(n) space — use hashset for O(1) lookups
        hashSet = set(nums)
        result = 0
        
        for num in nums: 
            # Only start counting from the beginning of a sequence
            if num - 1 not in hashSet:
                current = num
                streak = 0
                # Count consecutive numbers starting from this position
                while current in hashSet:
                    current += 1
                    streak += 1
                result = max(result, streak)
                
        return result