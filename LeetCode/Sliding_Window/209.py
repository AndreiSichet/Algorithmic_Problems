import math
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        minL=math.inf
        wndwS=0
        left=0
        for right in range(len(nums)):
            wndwS+=nums[right]
            while wndwS>=target:
                minL=min(minL,right-left+1)
                wndwS-=nums[left]
                left+=1
        return 0 if minL==math.inf else minL