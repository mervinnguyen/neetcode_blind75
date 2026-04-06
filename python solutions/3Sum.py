"""Find all unique triplets in an array that sum to zero.

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where 
nums[i] + nums[j] + nums[k] == 0, and the indices i, j, and k are all distinct.
The output should not contain any duplicate triplets in any order.
"""

from typing import List


class Solution:
    """Solution class for the 3Sum problem."""
    
    def threeSum(self, nums: list[int]) -> List[List[int]]:
        """Find all unique triplets in the array that sum to zero.
        
        This is a brute force approach that checks all possible triplets.
        Note: This implementation may return duplicate triplets and should be
        optimized for production use.
        
        Args:
            nums: List of integers to search for triplets.
            
        Returns:
            List of lists containing all triplets that sum to zero.
            
        Example:
            >>> solution = Solution()
            >>> solution.threeSum([-1, 0, 1, 2, -1, -4])
            [[-1, -1, 2], [-1, 0, 1]]
        """
        result = []
        nums.sort()
        
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                for k in range(j + 1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        temp = [nums[i], nums[j], nums[k]]
                        result.append(temp)
                        
        return result