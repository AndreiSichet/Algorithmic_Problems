
/*
Problem:

Given a grid where 0 means free and 1 means obstacle,
return the number of unique paths from the top-left
corner to the bottom-right corner.

The robot can only move right or down.

Key idea:

Use 2D Dynamic Programming.

dp[i][j] = number of valid paths from (0,0) to (i,j).

If the current cell is an obstacle:

    dp[i][j] = 0

Otherwise, the robot can arrive from:

    above: dp[i-1][j]
    left:  dp[i][j-1]

So:

    dp[i][j] = dp[i-1][j] + dp[i][j-1]

Base case:

    dp[0][0] = 1

If the starting cell is an obstacle, the answer is 0.

For the first row or first column, only one direction
is possible. If an obstacle appears, all cells after it
on that row or column become unreachable.

Example:

    0  0  1  0
    0  0  0  0
    0  0  0  0

dp:

    1  1  0  0
    1  2  2  2
    1  3  5  7

The obstacle makes dp[0][2] = 0, and therefore
dp[0][3] also becomes 0.

Time:
    O(m * n)

Space:
    O(m * n)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};