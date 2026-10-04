
/*
SLIDING WINDOW + DP - JUMP GAME VII

Goal:
- Determine whether index n-1 can be reached.
- We can jump from i to any j in:
    [i + minJump, i + maxJump]
- Destination must contain '0'.

DP:
- dp[i] = true if index i is reachable from index 0.

Naive approach:
- For every reachable i, check every position in its jump range.
- This can take O(n * maxJump), which is too slow.

Key observation:
- For index i, we only need to know whether there is ANY reachable index
  inside:
    [i - maxJump, i - minJump]
- If at least one position in this range is reachable and s[i] == '0',
  then i is reachable.

Sliding window:
- Maintain `reachable` = number of reachable indices currently inside
  [i - maxJump, i - minJump].
- As i moves right:
  1. Add the new index entering the window: i - minJump.
  2. Remove the index leaving the window: i - maxJump - 1.
  3. If s[i] == '0' and reachable > 0:
     dp[i] = true.

Important:
- Index 0 is reachable initially:
    dp[0] = true
- We do not need to physically store all reachable indices if we use
  the dp array + sliding window count.

Example:
s = "011010"
minJump = 2
maxJump = 3

Start:
dp[0] = true

For i = 2:
window = indices [0,0]
dp[0] = true
s[2] = '1' -> cannot land there

For i = 3:
window = indices [0,1]
dp[0] is reachable
s[3] = '0' -> dp[3] = true

For i = 5:
window = indices [2,3]
dp[3] is reachable
s[5] = '0' -> dp[5] = true

Therefore the last index is reachable.

Mental model:
- Each position i asks:
  "Is there a reachable zero within my valid jump range?"
- The valid range moves one position at a time.
- Instead of rescanning the whole range, maintain its number of reachable
  positions with a sliding window.

Complexity:
- Each index is added to and removed from the window once.
- Time: O(n)
- Space: O(n) for dp.
*/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int reachable = 0;
        for (int i = 1; i < n; i++) {
            int add = i - minJump;
            int remove = i - maxJump - 1;
            if (add >= 0 && dp[add])
                reachable++;
            if (remove >= 0 && dp[remove])
                reachable--;
            if (s[i] == '0' && reachable > 0)
                dp[i] = true;
        }
        return dp[n - 1];
    }
};