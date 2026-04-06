"""Best Time to Buy and Sell Stock solution.

This module contains a solution to the classic stock trading problem where you can
make at most one transaction (buy once, sell once) to maximize profit.
"""


class Solution:
    """Solution class for the Best Time to Buy and Sell Stock problem."""
    
    def maxProfit(self, prices: list[int]) -> int:
        """Find the maximum profit from buying and selling stock once.
        
        Given an array of stock prices, find the maximum profit that can be
        achieved by buying on one day and selling on a later day. If no profit
        is possible, return 0.
        
        Args:
            prices: List of integers representing stock prices on each day.
        
        Returns:
            Maximum profit achievable, or 0 if no profit possible.
            
        Example:
            >>> Solution().maxProfit([1, 5, 3, 6, 4])
            5
        """
        maxProf = 0
        for i in range(len(prices)):
            for j in range(i+1, len(prices)):
                maxProf = max(maxProf, prices[j] - prices[i])
        return maxProf


print(Solution().maxProfit([1,5,3,6,4]))