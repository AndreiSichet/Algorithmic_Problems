/*
Problem:

Given two strings s and t, return the number of distinct
subsequences of s which are equal to t.

A subsequence keeps the relative order of characters,
but characters can be skipped.

Key idea:

Use 2D Dynamic Programming.

dp[i][j] = number of ways to form the first j characters
           of t using the first i characters of s.

For example:

    dp[i][j]

uses:

    s[0 ... i-1]
    t[0 ... j-1]

If the current characters match:

    s[i-1] == t[j-1]

we have two choices:

    1. Use s[i-1] to match t[j-1]

       dp[i-1][j-1]

    2. Skip s[i-1]

       dp[i-1][j]

Therefore:

    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

If the characters do not match:

    s[i-1] != t[j-1]

we cannot use s[i-1] to match t[j-1].

So we must skip s[i-1]:

    dp[i][j] = dp[i-1][j]

Base cases:

    dp[i][0] = 1

There is exactly one way to form an empty string:
choose nothing.

    dp[0][j] = 0    for j > 0

We cannot form a non-empty t from an empty s.

Important:

The DP indices start at 1, but string indices start at 0.

Therefore:

    dp[i][j] -> s[i-1], t[j-1]

The final answer is:

    dp[m][n]

where:

    m = s.length()
    n = t.length()

Mental model:

When characters match:

    USE the character
        OR
    SKIP the character

So:

    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

When they do not match:

    SKIP the character

So:

    dp[i][j] = dp[i-1][j]

Use long long instead of int because the number of
subsequences can become very large.

Time:
    O(m * n)

Space:
    O(m * n)
*/
class Solution {
public:
    long long numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        // Empty t can always be formed by choosing nothing
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};