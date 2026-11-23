class Solution:
    def dailyTemperatures(self, temperatures:list[int])->list[int]:
        ans=[0]*len(temperatures)
        st=[]
        for i,t in enumerate(temperatures):
            while st and t>temperatures[st[-1]]:
                prev=st.pop()
                ans[prev]=i-prev
            st.append(i)
        return ans 