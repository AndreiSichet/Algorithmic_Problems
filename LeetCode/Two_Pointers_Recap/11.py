class Solution:
    def maxArea(self, heights:list[int])->int:
        left=0
        right=len(heights)-1
        maxA=0
        while left<right:
            currH=min(heights[left],heights[right])
            width=right-left
            currA=width*currH
            maxA=max(maxA,currA)
            if heights[left]<heights[right]:
                left+=1
            else:
                right-=1
        return maxA