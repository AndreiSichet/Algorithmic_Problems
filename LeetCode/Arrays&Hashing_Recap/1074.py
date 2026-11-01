class Solution:
    def numSubmatrixSumTarget(self, matrix: list[list[int]], target:int)->int:
        rows=len(matrix)
        cols=len(matrix[0])
        rez=0
        for top in range(rows):
            col_sums=[0]*cols
            for bottom in range(top,rows):
                for c in range(cols):
                    col_sums[c]+=matrix[bottom][c]
                freq={0:1}
                prefix=0
                for num in col_sums:
                    prefix+=num
                    rez+=freq.get(prefix-target,0)
                    freq[prefix]=freq.get(prefix,0)+1
        return rez