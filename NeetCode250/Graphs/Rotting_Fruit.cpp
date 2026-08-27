/*
Rotting Fruit:

Use MULTI-SOURCE BFS.

Every rotten fruit is a starting point.

Put all rotten fruits into the queue before
starting BFS.

Why all of them?

Because all rotten fruits start spreading
at minute 0.

Each BFS level represents one minute.

Example:

    2 1 1
    1 1 0
    0 1 1

Minute 0:

    2 1 1
    1 1 0
    0 1 1

Minute 1:

    2 2 1
    2 1 0
    0 1 1

Minute 2:

    2 2 2
    2 2 0
    0 1 1

For every rotten fruit, check its four neighbors.

If a neighbor is fresh:

    1. Make it rotten.
    2. Add it to the queue.
    3. Decrease the fresh count.

The important part is:

    int size = q.size();

We process exactly the fruits that were rotten
at the beginning of the current minute.

Any fruits that become rotten are added to
the queue for the next minute.

After processing one level:

    minutes++

If fresh becomes 0, all fruits have become rotten.

If the queue becomes empty while fresh > 0,
some fresh fruits cannot be reached.

In that case return -1.

Time:
    O(rows * cols)

Every cell is added to the queue at most once.

Space:
    O(rows * cols)

The queue can contain all cells in the worst case.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({ r, c });
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        int minutes = 0;
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                if (r > 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    fresh--;
                    q.push({ r - 1, c });
                }
                if (r + 1 < rows && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    fresh--;
                    q.push({ r + 1, c });
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    fresh--;
                    q.push({ r, c - 1 });
                }
                if (c + 1 < cols && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    fresh--;
                    q.push({ r, c + 1 });
                }
            }
            minutes++;
        }
        if (fresh > 0) {
            return -1;
        }
        return minutes;
    }
};