
/*
Problem:

Given an integer n, return the least number of perfect square numbers
that sum to n.

Key idea:

Use 1D Dynamic Programming.

dp[x] = minimum number of perfect squares needed to make x.

Base case:

dp[0] = 0

We need 0 squares to make the sum 0.

For every x, try every perfect square j*j <= x.

If j*j is the last square used:

    x = (x - j*j) + j*j

So:

    dp[x] = min(dp[x], dp[x - j*j] + 1)

Example:

n = 12

12 = 4 + 4 + 4

So dp[12] = 3.

For x = 12, we try:

    square = 1 -> dp[11] + 1
    square = 4 -> dp[8] + 1
    square = 9 -> dp[3] + 1

and take the minimum.

Time:
    O(n * sqrt(n))

Space:
    O(n)
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int sq = int(sqrt(i));
            for (int j = 1; j <= sq; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};