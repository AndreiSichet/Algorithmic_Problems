class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit=0
        left=0
        for right in range(len(prices)):
            day=prices[right]-prices[left]
            if day<0:
                left=right
            else:
                profit=max(profit,day)
        return profit  