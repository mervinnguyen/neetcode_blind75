"""Group anagrams from a list of strings.

This module provides a solution to group anagrams together into sublists.
An anagram is a string that contains the exact same characters as another
string, but the order of the characters can be different.
"""

class Solution:
    """Solution class for grouping anagrams."""
    
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        """Group all anagrams together into sublists.
        
        Uses sorted characters as keys to group anagrams. Strings with the
        same sorted characters are anagrams of each other.
        
        Args:
            strs: List of strings to group by anagrams.
            
        Returns:
            List of lists where each sublist contains anagrams grouped together.
            
        Example:
            >>> sol = Solution()
            >>> sol.groupAnagrams(["act", "cat", "hat"])
            [['act', 'cat'], ['hat']]
        """
        anagram_groups = {}
        
        for s in strs:
            sorted_chars = ''.join(sorted(s))
            if sorted_chars not in anagram_groups:
                anagram_groups[sorted_chars] = []
            anagram_groups[sorted_chars].append(s)
        
        return list(anagram_groups.values())

# Test cases
strs = ["act","pots","tops","cat","stop","hat"]
sol = Solution()
print(sol.groupAnagrams(strs))