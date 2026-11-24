class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        targetLen=len(s1)
        if targetLen>len(s2):
            return False
        targetF={}
        wndwF={}
        for i in range(targetLen):
            targetF[s1[i]]=targetF.get(s1[i],0)+1
            wndwF[s2[i]]=wndwF.get(s2[i],0)+1
        if targetF==wndwF:
            return True
        for right in range(targetLen,len(s2)):
            wndwF[s2[right]]=wndwF.get(s2[right],0)+1
            wndwF[s2[right-targetLen]]-=1
            if wndwF[s2[right-targetLen]]==0:
                del wndwF[s2[right-targetLen]]
            if targetF==wndwF:
                return True
        return False
