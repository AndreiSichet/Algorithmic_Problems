/*
Max Area of Island:

Use DFS.

Scan every cell in the grid.

When we find a land cell:

    grid[r][c] == 1

run DFS from that cell.

Instead of just marking the island as visited,
the DFS returns the number of cells in the island.

For every land cell:

    area = 1

Then add the areas of its four neighbors.

So:

    area =
        1
        + area above
        + area below
        + area left
        + area right

Water and out-of-bounds cells contribute:

    0

We mark visited land by changing:

    1 -> 0

This prevents visiting the same cell multiple times.

For every island, calculate its area and keep
the maximum.

Example:

    1 1 0
    1 0 0
    0 0 1

First island:

    1 1
    1

area = 3

Second island:

    1

area = 1

Maximum:

    3

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
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        // Mark this cell as visited.
        grid[r][c] = 0;
        int area = 1;
        area += dfs(grid, r - 1, c);
        area += dfs(grid, r + 1, c);
        area += dfs(grid, r, c - 1);
        area += dfs(grid, r, c + 1);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int area = dfs(grid, r, c);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};