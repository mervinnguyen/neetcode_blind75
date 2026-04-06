"""Products of Array Except Self solution.

This module implements a solution to find the product of all elements in an array
except the element at each index. The problem requires O(n) time complexity
without using division operations.
"""

from typing import List


class Solution:
    """Solution class for computing products of array elements except self."""

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """Return array where output[i] is product of all elements except nums[i].

        For each position i, calculates the product of all other elements in the array.
        Uses a brute force approach with O(n²) time complexity.

        Args:
            nums: List of integers where each product fits in 32-bit integer.

        Returns:
            List of integers where each element is the product of all elements
            in nums except the element at the corresponding index.

        Example:
            >>> solution = Solution()
            >>> solution.productExceptSelf([1, 2, 3, 4])
            [24, 12, 8, 6]
        """
        n = len(nums)
        res = [0] * n

        for i in range(n):
            prod = 1
            for j in range(n):
                if i != j:
                    prod *= nums[j]
            res[i] = prod
        
        return res