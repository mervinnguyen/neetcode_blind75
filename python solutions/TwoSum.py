"""Two Sum problem solver.

Given an array of integers and a target sum, finds the indices of two numbers
that add up to the target. Uses a brute force approach with nested loops.
"""

class Solution:
    """Solution class for the Two Sum problem."""
    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """Find two indices where the values sum to target.
        
        Given an array of integers nums and an integer target, return the 
        indices i and j such that nums[i] + nums[j] == target and i != j.
        Uses a brute force approach with O(n²) time complexity.
        
        Args:
            nums: List of integers to search through.
            target: Target sum value to find.
            
        Returns:
            List containing two indices [i, j] where nums[i] + nums[j] == target,
            with the smaller index first.
            
        Example:
            >>> solution = Solution()
            >>> solution.twoSum([3, 4, 5, 6], 7)
            [0, 1]
            >>> solution.twoSum([4, 5, 6], 10)
            [0, 2]
        """
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]