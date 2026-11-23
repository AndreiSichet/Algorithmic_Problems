import math
class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        st=[]
        for x in tokens:
            if x=='+':
                a=st.pop()
                b=st.pop()
                st.append(b+a)
            elif x=='-':
                a=st.pop()
                b=st.pop()
                st.append(b-a)
            elif x=='*':
                a=st.pop()
                b=st.pop()
                st.append(b*a)
            elif x=='/':
                a=st.pop()
                b=st.pop()
                st.append(math.trunc(b/a))
            else:
                st.append(int(x))
        return st[-1]