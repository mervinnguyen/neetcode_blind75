"""Longest Repeating Character Replacement solution.

This module contains a solution for finding the longest substring that can be made
to contain only repeating characters by replacing at most k characters.
"""


class Solution:
    """Solution for the Longest Repeating Character Replacement problem."""
    
    def characterReplacement(self, s: str, k: int) -> int:
        """Find the longest substring with repeating characters after at most k replacements.
        
        Uses a sliding window approach to find the longest valid substring where
        at most k character replacements are needed to make all characters the same.
        The algorithm maintains a window and tracks character frequencies, expanding
        when valid and contracting when the replacement limit is exceeded.
        
        Args:
            s: Input string containing uppercase English letters.
            k: Maximum number of character replacements allowed.
            
        Returns:
            Length of the longest substring that can be made repeating.
            
        Example:
            >>> sol = Solution()
            >>> sol.characterReplacement("ABAB", 2)
            4
            >>> sol.characterReplacement("AABABBA", 1)
            4
        """
        count = {}
        left = 0
        max_freq = 0
        result = 0

        for right in range(len(s)):
            char = s[right]
            count[char] = count.get(char, 0) + 1
            max_freq = max(max_freq, count[char])
            window_size = right - left + 1

            # O(1) amortized - shrink window when replacement limit exceeded
            while window_size - max_freq > k:
                left_char = s[left]
                count[left_char] -= 1
                left += 1
                window_size = right - left + 1

            result = max(result, window_size)
        
        return result
    

sol = Solution()
print(sol.characterReplacement("XYYX", 2))