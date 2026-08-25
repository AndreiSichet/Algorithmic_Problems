/*
Island Perimeter:

Every land cell has 4 sides.

A side contributes to the perimeter if it touches:

    1. Water
    2. The outside of the grid

So for every land cell, check its four directions.

Example:

    1 1
    1 1

Each cell has 4 sides:

    4 + 4 + 4 + 4 = 16

But neighboring land cells share sides.

There are 4 shared sides.

Each shared side removes 2 from the perimeter:

    16 - 4 * 2 = 8

Another way to think about it:

For every land cell:

    start with 4

    if the cell above is land:
        subtract 1

    if the cell below is land:
        subtract 1

    if the cell to the left is land:
        subtract 1

    if the cell to the right is land:
        subtract 1

We do not need DFS or BFS because the problem
only asks for the perimeter.

Time:
    O(row * col)

We inspect every cell once.

Space:
    O(1)

We only keep the perimeter count.

*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    continue;
                }
                // Every land cell starts with 4 sides.
                perimeter += 4;
                if (r > 0 && grid[r - 1][c] == 1) {
                    perimeter--;
                }
                if (r + 1 < rows && grid[r + 1][c] == 1) {
                    perimeter--;
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    perimeter--;
                }
                if (c + 1 < cols && grid[r][c + 1] == 1) {
                    perimeter--;
                }
            }
        }
        return perimeter;
    }
};