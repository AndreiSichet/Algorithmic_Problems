class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        left=1
        right=max(piles)
        minS=right
        def canEat(piles:list[int],k:int,h:int)->bool:
            hours=0
            for x in piles:
                hours+=x//k+(1 if x%k>0 else 0)
            return hours<=h
        while left<=right:
            mid=(left+right)//2
            if canEat(piles,mid,h):
                minS=min(minS,mid)
                right=mid-1
            else:
                left=mid+1
        return minS