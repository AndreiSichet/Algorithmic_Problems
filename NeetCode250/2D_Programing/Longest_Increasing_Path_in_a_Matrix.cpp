/*
Problem:

Given a 2D matrix of integers, return the length of the
longest strictly increasing path.

From each cell, you can move up, down, left, or right.
You cannot move diagonally.

Key idea:

Use DFS + 2D Dynamic Programming (memoization).

For every cell, calculate the longest increasing path
starting from that cell.

dp[r][c] = length of the longest increasing path
           starting at cell (r, c).

From (r, c), we can move to a neighboring cell only if:

    matrix[nr][nc] > matrix[r][c]

If we can move to that neighbor:

    dp[r][c] = max(dp[r][c],
                   1 + dfs(nr, nc))

The +1 represents the current cell.

Base case:

If there are no larger neighboring cells:

    dp[r][c] = 1

The path still contains the current cell.

Memoization:

If dp[r][c] has already been calculated, return it:

    if (dp[r][c] != 0)
        return dp[r][c]

This prevents recalculating the same cell multiple times.

Directions:

    down  -> (r + 1, c)
    up    -> (r - 1, c)
    right -> (r, c + 1)
    left  -> (r, c - 1)

We run DFS from every cell and take the maximum:

    answer = max(answer, dfs(r, c))

Important:

The problem has overlapping subproblems.

Different paths can reach the same cell, so without
memoization we would repeatedly calculate the same DFS.

Also, because we only move to strictly larger values,
we can never return to a previous cell in the same path.
This means there are no cycles in the increasing-path graph.

Think of each cell as a node:

    smaller -> larger -> larger -> ...

And DFS finds the longest path starting from each node.

Time:
    O(m * n)

Each cell is fully calculated only once.
Each cell checks 4 neighbors.

Space:
    O(m * n)

For the DP array and the recursion stack.
*/
class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, int r, int c) {
        // Already calculated
        if (dp[r][c] != 0)
            return dp[r][c];
        // At minimum, the path contains the current cell
        dp[r][c] = 1;
        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            // Check bounds
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                continue;
            // Only move to a strictly larger value
            if (matrix[nr][nc] <= matrix[r][c])
                continue;
            dp[r][c] = max(dp[r][c], 1 + dfs(matrix, nr, nc));
        }
        return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        dp.assign(rows, vector<int>(cols, 0));
        int answer = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                answer = max(answer, dfs(matrix, r, c));
            }
        }
        return answer;
    }
};