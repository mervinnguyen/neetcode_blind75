"""Trapping Rain Water problem solution.

This module implements a solution to the classic "Trapping Rain Water" problem
using a two-pointer approach to efficiently calculate the maximum water that
can be trapped between elevation bars.
"""

from typing import List


class Solution:
    """Solution class for the Trapping Rain Water problem."""
    
    def trap(self, height: List[int]) -> int:
        """Calculate the maximum area of water that can be trapped between bars.
        
        Uses a two-pointer approach with O(n) time complexity and O(1) space.
        The algorithm maintains left and right pointers along with the maximum
        heights seen from each side to determine water levels.
        
        Args:
            height: List of non-negative integers representing bar heights,
                   where each bar has width 1.
        
        Returns:
            The maximum volume of water that can be trapped as an integer.
        
        Example:
            >>> solution = Solution()
            >>> solution.trap([0,1,0,2,1,0,1,3,2,1,2,1])
            6
        """
        if not height or len(height) < 3:
            return 0
            
        left = 0
        right = len(height) - 1
        leftMax = height[left]
        rightMax = height[right]
        result = 0
        
        while left < right:
            if leftMax < rightMax:
                left += 1
                leftMax = max(leftMax, height[left])
                result += leftMax - height[left]
            else:
                right -= 1
                rightMax = max(rightMax, height[right])
                result += rightMax - height[right]
                
        return result