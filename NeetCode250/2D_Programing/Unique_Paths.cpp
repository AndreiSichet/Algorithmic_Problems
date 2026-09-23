
/*
Problem:

Given an m x n grid, move only right or down.
Return the number of unique paths from the top-left
corner to the bottom-right corner.

Key idea:

Use 2D Dynamic Programming.

dp[i][j] = number of unique paths from the top-left
           corner to cell (i, j).

A cell can only be reached from:

    1. The cell above: dp[i-1][j]
    2. The cell to the left: dp[i][j-1]

Therefore:

    dp[i][j] = dp[i-1][j] + dp[i][j-1]

Base cases:

    dp[0][0] = 1

Every cell in the first row has only one way to reach it:

    dp[0][j] = 1

Every cell in the first column has only one way to reach it:

    dp[i][0] = 1

Example:

    1  1  1
    1  2  3
    1  3  6

The answer is dp[m-1][n-1].

Time:
    O(m * n)

Space:
    O(m * n)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};