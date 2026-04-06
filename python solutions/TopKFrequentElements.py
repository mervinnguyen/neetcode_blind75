"""Find the k most frequent elements in an array.

This module provides a solution to find the k most frequent elements
in an integer array using frequency counting and sorting.
"""

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        """Return the k most frequent elements from the array.

        Args:
            nums: List of integers to analyze.
            k: Number of most frequent elements to return.

        Returns:
            List of the k most frequent elements in descending order of frequency.

        Example:
            >>> s = Solution()
            >>> s.topKFrequent([1,2,2,3,3,3], 2)
            [3, 2]
        """
        frequency = {}

        for n in nums:
            frequency[n] = frequency.get(n, 0) + 1
        
        # Create array of (frequency, number) pairs for sorting
        array = []
        for nums, freq in frequency.items():
            array.append((freq, nums))
        array.sort()

        inc = 0
        result = []
        while inc < k:
            result.append(array.pop()[1])
            inc += 1
        
        return result

# Test case
s = Solution()
print(s.topKFrequent([1,1,1,2,2,3], 2))