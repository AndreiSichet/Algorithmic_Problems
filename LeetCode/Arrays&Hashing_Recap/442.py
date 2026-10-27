class Solution:
    def findDuplicates(self,nums:list[int])->list[int]:
        rez=[]
        for num in nums:
            if nums[abs(num)-1]<0:
                rez.append(abs(num))
            else:
                nums[abs(num)-1]*=-1
        return rez