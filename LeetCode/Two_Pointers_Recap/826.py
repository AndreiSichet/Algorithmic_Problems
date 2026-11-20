class Solution:
    def maxProfitAssignment(self, difficulty: list[int], profit: list[int], workers: list[int]):
        jobs=sorted(zip(difficulty,profit))
        rez,i,best=0,0,0
        for worker in sorted(workers):
            while i<len(jobs) and worker>=jobs[i][0]:
                best=max(best,jobs[i][1])
                i+=1
            rez+=best
        return rez