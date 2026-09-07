/*
Swim in Rising Water:

Use Dijkstra's algorithm.

The important difference from normal Dijkstra:

Normal Dijkstra:
newDist = distance + edgeCost

Here:
newDist = max(distance, grid[next][nextCol])

Why?

The cost of a path is the highest elevation on that path.

Example:

```
0 -> 2 -> 5 -> 3 -> 7
```

The water must reach 7 to use this path.

So:

```
path cost = 7
```

We want the path whose highest elevation is as small as possible.

dist[r][c] means:

```
The minimum water level needed to reach cell (r,c).
```

Start:

```
dist[0][0] = grid[0][0]
```

Use a min-heap:

```
{requiredWater, row, col}
```

Always process the cell that currently requires
the smallest water level.

For every neighbor:

```
newDist = max(currentDistance, neighborElevation)
```

If newDist is smaller than the best known distance
for that neighbor, update it and push it into the heap.

Once we reach the bottom-right cell, that distance
is the minimum possible time.

Complexity:

There are n * n cells.

Each cell can be processed and each of its 4 neighbors
can be checked.

Time:
O(n^2 log(n^2))

which is equivalent to:

```
O(n^2 log n)
```

Space:
O(n^2)
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({ grid[0][0], 0, 0 });
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        while (!pq.empty()) {
            auto [distance, r, c] = pq.top();
            pq.pop();
            if (distance > dist[r][c]) {
                continue;
            }
            if (r == n - 1 && c == n - 1) {
                return distance;
            }
            for (auto& direction : directions) {
                int nr = r + direction[0];
                int nc = c + direction[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                    continue;
                }
                int newDist = max(distance, grid[nr][nc]);
                if (newDist < dist[nr][nc]) {
                    dist[nr][nc] = newDist;
                    pq.push({ newDist, nr, nc });
                }
            }
        }
        return -1;
    }
};
