class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        groups={}
        for s in strs:
            count=[0]*26
            for c in s:
                index=ord(c)-ord('a')
                count[index]+=1
            key=tuple(count)
            groups.setdefault(key,[]).append(s)
        return list(groups.values()) 