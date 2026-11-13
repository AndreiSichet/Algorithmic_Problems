class Solution:
    def reverseVowels(self, s: str) -> str:
        rez=list(s)
        vowels=set("aeiouAEIOU")
        left=0
        right=len(rez)-1
        while left<=right:
            while left<right and rez[left] not in vowels:
                left+=1
            while left<right and rez[right] not in vowels:
                right-=1
            rez[left],rez[right]=rez[right],rez[left]
            left+=1
            right-=1
        return ''.join(rez)