"""Find the length of the longest substring without repeating characters.

Given a string s, find the length of the longest substring without duplicate characters.
A substring is a contiguous sequence of characters within a string.
"""

from unittest import result


class Solution:
    """Solution for finding longest substring without repeating characters."""
    
    def lengthOfLongestSubstring(self, s: str) -> int:
        """Find the length of the longest substring without repeating characters.
        
        Uses a sliding window approach with two pointers (left and right) and a set
        to track characters in the current window. When a duplicate is found, shrink
        the window from the left until the duplicate is removed.
        
        Args:
            s: The input string to analyze.
            
        Returns:
            The length of the longest substring without repeating characters.
            
        Example:
            >>> Solution().lengthOfLongestSubstring("abcabcbb")
            3
        """
        charSet = set()
        left = 0
        result = 0
        
        for right in range(len(s)):
            while s[right] in charSet:
                charSet.remove(s[left])
                left += 1
            charSet.add(s[right])
            result = max(result, right - left + 1)
        return result

print(Solution().lengthOfLongestSubstring("abcabcbb"))