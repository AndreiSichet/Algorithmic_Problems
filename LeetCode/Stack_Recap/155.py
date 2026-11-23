class Solution:
    def __init__(self):
        self.st=[]
        self.minst=[]
    def push(self,value:int)->None:
        self.st.append(value)
        if not self.minst:
            self.minst.append(value)
        else:
            self.minst.append(min(value,self.minst[-1]))
    def pop(self)->int:
        self.st.pop()
        self.minst.pop()
    def top(self)->int:
        return self.st[-1]
    def getMin(self)->int:
        return self.minst[-1]
