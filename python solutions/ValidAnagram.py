"""Valid Anagram checker.

This module provides a solution to determine if two strings are anagrams of each other.
An anagram is a string that contains the exact same characters as another string,
but the order of the characters can be different.
"""


class Solution:
    """Solution class for checking if two strings are anagrams."""

    def isAnagram(self, s: str, t: str) -> bool:
        """Check if two strings are anagrams of each other.

        Args:
            s: First string to compare.
            t: Second string to compare.

        Returns:
            True if the strings are anagrams, False otherwise.

        Example:
            >>> solution = Solution()
            >>> solution.isAnagram("listen", "silent")
            True
            >>> solution.isAnagram("rat", "car")
            False
        """
        s = sorted(s)
        t = sorted(t)
        if s == t:
            return True
        else:
            return False