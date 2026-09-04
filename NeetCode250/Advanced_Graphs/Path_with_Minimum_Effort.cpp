
/*
Path with Minimum Effort:

Treat every cell as a node in a graph.

The cost of moving between two neighboring cells is:

    abs(height1 - height2)

But unlike normal shortest path problems,
we do not add the costs.

The effort of a path is the maximum cost along that path.

Example:

    Path: A -> B -> C

    costs:
        2, 5

    effort:
        max(2, 5) = 5

So for every cell we store the minimum possible
maximum effort needed to reach that cell.

This can be solved using Dijkstra.

For the current cell:

    currentEffort

Moving to a neighbor requires:

    abs(currentHeight - neighborHeight)

The effort of the new path is:

    max(currentEffort, moveEffort)

If this is smaller than the previously known effort
for the neighbor, update it and put the neighbor
into the priority queue.

The priority queue always gives us the cell with the
smallest known effort.

Once we remove the bottom-right cell from the queue,
we have found the minimum possible effort.

Time:
    O(R * C * log(R * C))

Space:
    O(R * C)
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows,vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;
        dist[0][0] = 0;
        pq.push({ 0, 0, 0 });
        int dr[] = { -1, 1, 0, 0 };
        int dc[] = { 0, 0, -1, 1 };
        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();
            if (effort > dist[r][c]) {
                continue;
            }
            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                    continue;
                }
                int moveEffort = abs(heights[r][c] - heights[nr][nc]);
                int newEffort = max(effort, moveEffort);
                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({ newEffort, nr, nc });
                }
            }
        }
        return 0;
    }
};
