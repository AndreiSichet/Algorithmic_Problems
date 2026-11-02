class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n=len(nums)
        rez=[1]*n
        for i in range(1,n):
            rez[i]=rez[i-1]*nums[i-1]
        suf=1
        for i in range(n-2,-1,-1):
            suf*=nums[i+1]
            rez[i]*=suf
        return rez
