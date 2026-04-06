"""Container With Most Water solution.

Given an integer array of heights, find two bars that can form a container
to store the maximum amount of water using the two-pointer technique.
"""

from typing import List


class Solution:
    """Solution for the Container With Most Water problem."""

    def maxArea(self, heights: List[int]) -> int:
        """Find the maximum amount of water that can be stored between two bars.

        Uses the two-pointer approach to efficiently find the optimal container.
        The area is determined by the shorter bar and the distance between bars.

        Args:
            heights: List of integers representing the height of each bar.

        Returns:
            The maximum water area that can be contained between any two bars.

        Example:
            >>> solution = Solution()
            >>> solution.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7])
            49
        """
        left = 0
        right = len(heights) - 1
        result = 0

        while left < right:
            area = min(heights[left], heights[right]) * (right - left)
            result = max(result, area)

            # Move the pointer with the shorter height to potentially find a taller bar
            if heights[left] <= heights[right]:
                left += 1
            else:
                right -= 1

        return result