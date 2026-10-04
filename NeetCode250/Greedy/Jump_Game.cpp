
/*
GREEDY - JUMP GAME

Goal:
- Determine if index n-1 can be reached from index 0.
- nums[i] is the maximum number of positions we can jump from i.

Key idea:
- We do NOT need to know the exact path.
- Track the farthest index reachable from all positions processed so far.
- If we can reach i, then from i we can reach up to i + nums[i].
- Therefore:
    farthest = max(farthest, i + nums[i])

Algorithm:
1. Start with farthest = 0 because we begin at index 0.
2. Scan the array from left to right.
3. Before processing i:
   - If i > farthest, index i is unreachable.
   - Since we cannot reach i, we can never reach the end -> false.
4. Otherwise, i is reachable:
   - Extend the reachable range:
     farthest = max(farthest, i + nums[i])
5. If farthest >= n-1, the last index is reachable -> true.
6. If the loop finishes, return true.

Mental model:
- farthest represents the boundary of the region we can currently reach.
- Every reachable index can potentially extend this boundary.
- We only care about the maximum boundary, not individual jump paths.

Example:
nums = [2,3,1,1,4]

i=0 -> farthest = 2
i=1 -> farthest = 4
Since farthest reaches index 4 -> true.

Failure example:
nums = [3,2,1,0,4]

i=0 -> farthest = 3
i=1 -> farthest = 3
i=2 -> farthest = 3
i=3 -> farthest = 3
i=4 -> i > farthest
Index 4 cannot be reached -> false.

Why greedy works:
- At every step, only the farthest reachable position matters.
- If a position is reachable, any shorter reachable position cannot give us more reach than
  the maximum already tracked.
- Therefore keeping only farthest loses no information.

Complexity:
- Time: O(n)
- Space: O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest)
                return false;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= nums.size() - 1)
                return true;
        }
        return true;
    }
};