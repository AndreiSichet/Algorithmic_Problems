
/*
Problem:

Find the minimum cost to reach the top.

We can start at index 0 or index 1.

From every index, we can move one or two positions.

Key idea:

Let dp[i] be the minimum cost needed to reach position i.

To reach position i, we can come from:
    i - 1
    i - 2

If we come from i - 1, we pay cost[i - 1].
If we come from i - 2, we pay cost[i - 2].

Therefore:

dp[i] = min(
    dp[i - 1] + cost[i - 1],
    dp[i - 2] + cost[i - 2]
)

The top is position cost.size().

We can start at positions 0 and 1 for free:

    dp[0] = 0
    dp[1] = 0

We only need the previous two dp values,
so we can solve it using O(1) extra space.

Time:
    O(n)

Space:
    O(1)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = 0;
        int prev1 = 0;
        for (int i = 2; i <= n; i++) {
            int current = min(prev1 + cost[i - 1],prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
