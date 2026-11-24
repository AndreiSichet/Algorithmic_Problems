from collections import defaultdict
class TimeMap:
    def __init__(self):
        self.store:dict[str,list[tuple[int,str]]]=defaultdict(list)
    def set(self,key:str,value:str,timestamp:int)->None:
        self.store[key].append((timestamp,value))
    def get(self,key:str,timestamp:int)->str:
        entries=self.store[key]
        if not entries:
            return ""
        left,right=0,len(entries)-1
        rez=""
        while left<=right:
            mid=(left+right)//2
            ts,val=entries[mid]
            if ts<=timestamp:
                rez=val
                left=mid+1
            else:
                right=mid-1
        return rez