class Solution:
    def smallestDistancePair(self, nums: list[int], k: int) -> int:
        nums.sort()
        n=len(nums)
        def count_pairs(max_dist:int)->int:
            count=0
            left=0
            for right in range(n):
                while nums[right]-nums[left]>max_dist:
                    left+=1
                count+=right-left
            return count
        low,high=0,nums[-1]-nums[0]
        while low<high:
            mid=(high+low)//2
            if count_pairs(mid)<k:
                low=mid+1
            else:
                high=mid
        return low