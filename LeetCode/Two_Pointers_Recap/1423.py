class Solution:
    def maxScore(self,cardPoints:list[int],k:int)->int:
        n=len(cardPoints)
        total=sum(cardPoints)
        if n==k:
            return total
        wnw_size=n-k
        wnw_sum=sum(cardPoints[:wnw_size])
        min_wnw_sum=wnw_sum
        for i in range(wnw_size,n):
            wnw_sum+=cardPoints[i]-cardPoints[i-wnw_size]
            min_wnw_sum=min(min_wnw_sum,wnw_sum)
        return total-min_wnw_sum