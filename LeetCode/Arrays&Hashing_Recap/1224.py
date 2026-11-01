class Solution:
    def maxEqualFreq(self, nums: list[int]) -> int:
        freq = {}
        count = {}
        maxfreq = 0
        rez = 0
        for i, num in enumerate(nums):
            oldF = freq.get(num, 0)
            if oldF > 0:
                count[oldF] -= 1
            freqN = oldF + 1
            freq[num] = freqN
            count[freqN] = count.get(freqN, 0) + 1
            maxfreq = max(maxfreq, freqN)
            n = i + 1
            unique = len(freq)
            if maxfreq == 1:
                rez = n

            elif count.get(1, 0) == 1 and count.get(maxfreq, 0) == unique - 1:
                rez = n

            elif count.get(maxfreq, 0) == 1 and count.get(maxfreq - 1, 0) == unique - 1:
                rez = n
        return rez