class Solution:
    def subarrayDivByK(self, nums:list[int],k:int)->int:
        prefix=0
        rez=0
        freq={0:1}
        for num in nums:
            prefix+=num
            r=prefix%k
            rez+=freq.get(r,0)
            freq[r]=freq.get(r,0)+1
        return rez  