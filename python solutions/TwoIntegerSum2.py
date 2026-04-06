"""Two Integer Sum II - Input Array Is Sorted

Given an array of integers sorted in non-decreasing order, find two numbers
that add up to a target using two pointers with O(1) space complexity.
"""

class Solution:
    """Solution class for finding two integers that sum to target in sorted array."""
    
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        """Find two numbers in sorted array that add up to target.

        Uses two pointers approach: start from both ends and move inward based on
        current sum compared to target. Since array is sorted, if sum is too large,
        move right pointer left; if sum is too small, move left pointer right.

        Args:
            numbers: Sorted array of integers in non-decreasing order.
            target: Target sum value.

        Returns:
            List containing the two numbers that sum to target (not indices).
            There is always exactly one valid solution.

        Example:
            >>> solution = Solution()
            >>> solution.twoSum([2, 7, 11, 15], 9)
            [2, 7]
        """
        left = 0
        right = len(numbers) - 1
        result = []
        
        while left < right:
            sum = numbers[left] + numbers[right]

            if sum == target:
                result.append(numbers[left])
                result.append(numbers[right])
                return result
            if sum > target:
                right -= 1
            if sum < target:
                left += 1

# Test case
solution = Solution()
print(solution.twoSum([2,7,11,15], 9))  # [2,7]