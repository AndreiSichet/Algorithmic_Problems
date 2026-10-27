class Solution:
    def numIdenticalPairs(self,nums:list[int])->int:
        freq={}
        for a in nums:
            freq[a]=freq.get(a,0)+1
        rez=0
        for count in freq.values():
            if count>1:
                rez=rez+count*(count-1)//2
        return rez