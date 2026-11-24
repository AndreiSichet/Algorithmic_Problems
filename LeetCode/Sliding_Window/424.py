class Solution:
    def characterReplacement(self,s:str,k:int)->int:
        freq={}
        count=0
        maxL=0
        left=0
        for right in range(len(s)):
            freq[s[right]]=freq.get(s[right],0)+1
            count=max(count,freq[s[right]])
            while right-left+1-count>k:
                freq[s[left]]-=1
                left+=1
            maxL=max(maxL,right-left+1)
        return maxL