class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        nums_set = set(nums)
        rez = 0
        for num in nums_set:
            if num - 1 not in nums_set:
                count = 1
                while num + count in nums_set:
                    count += 1
                rez = max(rez, count)

        return rez