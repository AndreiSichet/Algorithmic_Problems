/*
Pacific Atlantic Water Flow:

Use DFS from both oceans.

Normally water flows:

    higher -> lower

Instead of starting from every cell and trying to
reach the oceans, reverse the problem.

Start from the oceans and move toward cells that
could have flowed into the ocean.

In reverse:

    lower -> higher

So from a cell with height h, we can visit a neighbor
if:

    neighbor height >= h

Pacific Ocean:

    top row
    left column

Start DFS from every cell on those borders.

Atlantic Ocean:

    bottom row
    right column

Start DFS from every cell on those borders.

This gives us two visited arrays:

    pacific[r][c]
        true if the cell can reach the Pacific

    atlantic[r][c]
        true if the cell can reach the Atlantic

A cell belongs in the answer if:

    pacific[r][c] && atlantic[r][c]

Example:

    Pacific
    top
    left

    +---+---+---+
    | P | P | P |
    +---+---+---+
    | P |   |   |
    +---+---+---+
    | P |   | A |
    +---+---+---+
              |
           Atlantic

The Pacific DFS marks every cell that can reach
the Pacific.

The Atlantic DFS marks every cell that can reach
the Atlantic.

The intersection of the two sets is the answer.

Why reverse the flow?

Suppose:

    5
    |
    3
    |
    1
    |
    Ocean

Water can flow:

    5 -> 3 -> 1 -> Ocean

Starting from the ocean, we can reverse this:

    Ocean -> 1 -> 3 -> 5

So while doing DFS from the ocean, we move to
neighbors with height equal or greater than the
current cell.

Time:
    O(rows * cols)

Each cell is visited at most once for each ocean.

Space:
    O(rows * cols)

For the two visited arrays and recursion stack.
*/

class Solution {
public:
    int rows;
    int cols;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        if (r > 0 && !visited[r - 1][c] && heights[r - 1][c] >= heights[r][c]) {
            dfs(heights, visited, r - 1, c);
        }
        if (r + 1 < rows && !visited[r + 1][c] && heights[r + 1][c] >= heights[r][c]) {
            dfs(heights, visited, r + 1, c);
        }
        if (c > 0 && !visited[r][c - 1] && heights[r][c - 1] >= heights[r][c]) {
            dfs(heights, visited, r, c - 1);
        }
        if (c + 1 < cols && !visited[r][c + 1] && heights[r][c + 1] >= heights[r][c]) {
            dfs(heights, visited, r, c + 1);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pacific( rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic( rows, vector<bool>(cols, false));
        // Start from the Pacific borders.
        for (int c = 0; c < cols; c++) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, rows - 1, c);
        }
        for (int r = 0; r < rows; r++) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, cols - 1);
        }
        vector<vector<int>> rez;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    rez.push_back({ r, c });
                }
            }
        }
        return rez;
    }
};