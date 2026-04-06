"""Encode and decode strings algorithm implementation.

Design an algorithm to encode a list of strings to a string. The
encoded string is then sent over the network and is decoded back to the original list of strings.
"""

from typing import List


class Solution:
    """Solution class for encoding and decoding lists of strings."""
    
    def encode(self, strs: List[str]) -> str:
        """Encode a list of strings into a single string.
        
        The encoding format stores the length of each string followed by a delimiter,
        then concatenates all the original strings.
        
        Args:
            strs: List of strings to encode.
            
        Returns:
            Encoded string representation of the input list.
            
        Example:
            >>> sol = Solution()
            >>> sol.encode(["hello", "world"])
            "5,5,#helloworld"
        """
        if not strs:
            return " "
        sizes = []
        for string in strs:
            sizes.append(len(string))
        result = " "
        for size in sizes:
            result = str(size) + ","
        result += "#"
        for s in strs:
            result += s
        return result
    
    def decode(self, s: str) -> List[str]:
        """Decode an encoded string back to the original list of strings.
        
        Parses the encoded format to extract string lengths, then reconstructs
        the original strings using those lengths.
        
        Args:
            s: Encoded string to decode.
            
        Returns:
            List of original strings.
            
        Raises:
            ValueError: If the encoded string format is invalid.
            
        Example:
            >>> sol = Solution()
            >>> sol.decode("5,5,#helloworld")
            ["hello", "world"]
        """
        if not s:
            return []
        sizes = []
        result = []
        i = 0

        while s[i] != "#":
            current = " "
            while s[i] != ",":
                current += s[i]
                i += 1
            sizes.append(int(current))
            i += 1
        i += 1
        for size in sizes:
            result.append(s[i:i + size])
            i += size
        return result