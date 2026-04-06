"""Valid Palindrome solution.

Given a string s, return true if it is a palindrome, otherwise return false.
A palindrome is a string that reads the same forward and backward. It is also 
case-insensitive and ignores all non-alphanumeric characters.
"""


class Solution:
    """Solution class for palindrome validation."""

    def isPalindrome(self, s: str) -> bool:
        """Check if a string is a valid palindrome.

        Uses a two-pointer approach to efficiently check palindrome property.
        Ignores non-alphanumeric characters and is case-insensitive.

        Args:
            s: The input string to check.

        Returns:
            True if the string is a palindrome, False otherwise.

        Example:
            >>> solution = Solution()
            >>> solution.isPalindrome("A man, a plan, a canal: Panama")
            True
            >>> solution.isPalindrome("race a car")
            False
        """
        # Two pointer approach: O(n) time, O(1) space
        left = 0
        right = len(s) - 1

        while left < right:
            # Skip non-alphanumeric characters from left
            while left < right and not s[left].isalnum():
                left += 1
            # Skip non-alphanumeric characters from right
            while left < right and not s[right].isalnum():
                right += 1

            if s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        return True