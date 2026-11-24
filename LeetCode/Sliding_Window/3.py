class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chars=set()
        length=0
        left=0
        for right in range(len(s)):
            while s[right] in chars:
                chars.discard(s[left])
                left+=1
            chars.add(s[right])
            length=max(length,right-left+1)
        return length