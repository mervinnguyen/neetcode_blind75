"""Contains Duplicate

Given an integer array nums, return true if any value appears more than once 
in the array, otherwise return false.
"""

from typing import List


class Solution:
    """Solution class for the Contains Duplicate problem."""
    
    def hasDuplicate(self, nums: List[int]) -> bool:
        """Check if any value appears more than once in the array.
        
        Uses a hash map to track seen values while iterating through the array.
        Returns True as soon as a duplicate is found for O(1) early termination.
        
        Args:
            nums: List of integers to check for duplicates.
            
        Returns:
            True if any value appears more than once, False otherwise.
            
        Example:
            >>> solution = Solution()
            >>> solution.hasDuplicate([1, 2, 3, 1])
            True
            >>> solution.hasDuplicate([1, 2, 3, 4])
            False
        """
        hashmap = {}
        for i in nums:
            if i in hashmap:
                return True
            hashmap[i] = 1
        return False