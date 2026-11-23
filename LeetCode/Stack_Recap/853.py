class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:
        position_speed=sorted(zip(position,speed),reverse=True)
        st=[]
        for x in position_speed:
            time=(target-x[0])/x[1]
            if st and time<=st[-1]:
                continue
            else:
                st.append(time)
        return len(st)