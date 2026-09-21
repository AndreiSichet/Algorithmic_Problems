
/*
Problem:

Given an integer n, break it into the sum of at least two
positive integers and maximize their product.

Key idea:

Use 1D Dynamic Programming.

dp[x] = maximum product obtainable by breaking x.

For every x, choose j as the first part:

    x = j + (x-j)

There are two possibilities:

1. Stop splitting the remaining part:

    j * (x-j)

2. Continue splitting the remaining part:

    j * dp[x-j]

Therefore:

    dp[x] = max(dp[x],
                j * (x-j),
                j * dp[x-j])

We only check j <= x/2 because:

    j + (x-j)

and

    (x-j) + j

produce the same product.

Base case:

    dp[1] = 0

1 cannot be split into at least two positive integers.

Example:

n = 10

10 = 3 + 3 + 4

product = 3 * 3 * 4 = 36

So dp[10] = 36.

Time:
    O(n^2)

Space:
    O(n)
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], j * (i - j));
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        return dp[n];
    }
};