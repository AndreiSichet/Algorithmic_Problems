
/*
GREEDY - JUMP GAME II

Goal:
- Reach the last index using the minimum number of jumps.
- A jump from i can reach any index from i+1 to i+nums[i].

Key idea:
- Treat each jump as creating a reachable range.
- While scanning the current range, find the farthest index that the NEXT jump can reach.
- When we reach the end of the current range, we must make another jump.
- This is similar to BFS levels:
    current range = positions reachable with the current number of jumps
    next range = positions reachable after one more jump

Variables:
- jumps = number of jumps made so far
- currentEnd = farthest index reachable using jumps jumps
- farthest = farthest index reachable using jumps + 1 jumps

Algorithm:
1. Start:
   jumps = 0
   currentEnd = 0
   farthest = 0

2. Scan i from 0 to n-2.
   We do not need to process the last index because reaching it is the goal.

3. For every i inside the current reachable range:
   farthest = max(farthest, i + nums[i])
   This determines how far we could get with the next jump.

4. When i reaches currentEnd:
   - We have finished checking every position reachable with the current
     number of jumps.
   - We must make another jump.
   - jumps++
   - currentEnd = farthest

5. Once currentEnd reaches the last index, jumps is the minimum answer.

Example:
nums = [2,3,1,1,4]

Start:
jumps = 0
currentEnd = 0
farthest = 0

i=0:
farthest = max(0, 0+2) = 2
i == currentEnd -> make jump
jumps = 1
currentEnd = 2

Now positions 1 and 2 are reachable with 1 jump.

i=1:
farthest = max(2, 1+3) = 4

i=2:
farthest = max(4, 2+1) = 4
i == currentEnd -> make jump
jumps = 2
currentEnd = 4

Last index reached -> answer = 2.

Why greedy gives the minimum:
- We do not choose a specific destination immediately.
- For the current jump, examine every position we can reach.
- Choose the next range based on the position that gives the farthest reach.
- Therefore, each jump expands the reachable range as much as possible.
- This is equivalent to taking the minimum number of BFS levels needed to reach
  the last index.

Mental model:
- currentEnd = end of the current "level"
- farthest = end of the next "level"
- When we reach currentEnd, move to the next level and increment jumps.

Complexity:
- Time: O(n)
- Space: O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};