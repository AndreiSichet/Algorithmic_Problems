
/*
Problem:

Given a grid of non-negative numbers, find the path from
the top-left corner to the bottom-right corner with the
minimum possible sum.

The robot can only move right or down.

Key idea:

Use 2D Dynamic Programming.

dp[i][j] = minimum path sum needed to reach cell (i,j)
           from the top-left corner.

To reach (i,j), we can come from:

    above: dp[i-1][j]
    left:  dp[i][j-1]

Therefore:

    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])

Base case:

    dp[0][0] = grid[0][0]

For the first row, we can only come from the left.

For the first column, we can only come from above.

Example:

    1  3  1
    1  5  1
    4  2  1

DP table:

    1  4  5
    2  7  6
    6  8  7

Answer:

    7

Path:

    1 -> 3 -> 1 -> 1 -> 1

Time:
    O(m * n)

Space:
    O(m * n)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i > 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                if (j > 0) {
                    if (i == 0) {
                        dp[i][j] = dp[i][j - 1] + grid[i][j];
                    }
                    else {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};