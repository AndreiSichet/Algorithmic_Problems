/*
Islands and Treasure:

Use MULTI-SOURCE BFS.

We want the distance from every land cell to
the nearest treasure chest.

A normal BFS would start from one chest.

But there can be multiple chests.

So we put ALL treasure chests into the queue
before starting BFS.

Example:

    INF INF INF
    INF  0  INF
    INF INF  0

Initial queue:

    [chest, chest]

Both chests have distance 0.

BFS then expands from all of them simultaneously.

The first time a land cell is reached, we know
that we reached it using the shortest possible path
from the nearest chest.

For a cell with distance d:

    neighbor distance = d + 1

We only visit cells that are:

    INF

We do not traverse:

    -1

because water cannot be traversed.

We also do not revisit cells that already have
a distance.

Example:

    0  INF INF

After BFS:

    0   1   2

The distance increases by 1 for every step.

Why multi-source BFS?

Suppose we have:

    0  INF INF INF  0

Both chests start at distance 0.

The BFS expands:

    0  1  2  1  0

If we started BFS from each chest separately,
we would repeat a lot of work.

With multi-source BFS, both searches happen
at the same time.

We modify the grid in-place.

So the grid itself tells us whether a cell has
already been visited:

    INF -> not visited
    value other than INF -> already processed

Time:
    O(m * n)

Every cell is added to the queue at most once.

Space:
    O(m * n)

The queue can contain every cell in the worst case.
*/

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // Add every treasure chest as a source.
                if (grid[r][c] == 0) {
                    q.push({ r, c });
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int distance = grid[r][c] + 1;
            if (r > 0 && grid[r - 1][c] == INT_MAX) {
                grid[r - 1][c] = distance;
                q.push({ r - 1, c });
            }
            if (r + 1 < rows && grid[r + 1][c] == INT_MAX) {
                grid[r + 1][c] = distance;
                q.push({ r + 1, c });
            }
            if (c > 0 && grid[r][c - 1] == INT_MAX) {
                grid[r][c - 1] = distance;
                q.push({ r, c - 1 });
            }
            if (c + 1 < cols && grid[r][c + 1] == INT_MAX) {
                grid[r][c + 1] = distance;
                q.push({ r, c + 1 });
            }
        }
    }
};