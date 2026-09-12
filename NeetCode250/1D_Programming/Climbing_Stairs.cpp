
/*
Problem:

Count the number of ways to reach stair n.

At every move we can climb either 1 or 2 stairs.

Key idea:

Look at the final move.

If the final move is 1 step:
    The previous stair was n - 1.
    Number of ways = ways[n - 1].

If the final move is 2 steps:
    The previous stair was n - 2.
    Number of ways = ways[n - 2].

Therefore:

    ways[n] = ways[n - 1] + ways[n - 2]

Base cases:

    ways[1] = 1
    ways[2] = 2

We only need the previous two values, so we can use
two variables instead of a DP array.

Time:
    O(n)

Space:
    O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int prev2 = 1;
        int prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
