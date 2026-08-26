/*
Number of Islands:

Use DFS.

Scan every cell in the grid.

If we find:

    grid[r][c] == '1'

then we found a new island.

Increase the island count and run DFS from
that cell.

The DFS visits every land cell connected to
the starting cell.

During DFS:

    1. Check if the cell is outside the grid.
    2. Check if it is water.
    3. Mark the land cell as visited.
    4. Explore its four neighbors.

We can mark a visited land cell by changing:

    '1' -> '0'

This removes the need for a separate visited array.

Example:

    1 1 0
    1 0 0
    0 0 1

Start scanning:

    Find first 1

    count = 1

DFS removes the entire first island:

    0 0 0
    0 0 0
    0 0 1

Continue scanning.

Find the last 1:

    count = 2

DFS removes it.

Final answer:

    2

Why does this work?

Each island has at least one land cell.

The first time we encounter an island,
we count it once and DFS removes every
connected land cell.

Therefore we can never count the same island twice.

Time:
    O(rows * cols)

Every cell is visited at most once.

Space:
    O(rows * cols)

In the worst case, the DFS recursion can contain
every cell in the grid.
*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        // Mark this land cell as visited.
        grid[r][c] = '0';
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }
        return islands;
    }
};