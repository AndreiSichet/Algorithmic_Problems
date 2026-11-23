class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        pairs = {')': '(', ']': '[', '}': '{'}
        for x in s:
            if x in pairs:
                if not st or st.pop() != pairs[x]:
                    return False
            else:
                st.append(x)          
        return not st
