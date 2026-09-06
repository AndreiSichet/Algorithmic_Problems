/*
Min Cost to Connect Points:

This is a Minimum Spanning Tree problem.

We have points and can connect any two points.

The cost of connecting:

```
[x1, y1] and [x2, y2]
```

is their Manhattan distance:

```
|x1 - x2| + |y1 - y2|
```

We need to connect ALL points with the minimum total cost.

The important phrase is:

```
"There exists exactly one path between each pair of points."
```

This means the final graph must be a TREE.

A tree:
- connects all nodes
- has no cycles
- has exactly n - 1 edges

So we need a Minimum Spanning Tree (MST).

We can use Prim's algorithm.

Prim's idea:

```
Start with any point.

Repeatedly:
    1. Find the cheapest edge connecting a point
       already in our tree to a point outside our tree.
    2. Add that point to the tree.
    3. Add the edge cost to the answer.
```

We use a min-heap to quickly find the cheapest connection.

Example:

```
Points:

    A       B

    C       D
```

Start at A.

Suppose the cheapest connection from A is A -> C.

Tree:
A -- C

Now we look for the cheapest edge connecting:
{A, C}
to a point outside:
{B, D}

Suppose C -> D is cheapest.

Tree:
A -- C -- D

Then maybe D -> B is cheapest.

Tree:
A -- C -- D -- B

All points are now connected.

Important:

We do NOT need to explicitly build all edges.

For every point, we can calculate its distance to every other point
when we need it.

We maintain:

```
minDist[i]
```

This means:

```
The cheapest cost currently known to connect point i
to the tree.
```

Initially:

```
minDist[0] = 0
```

because we start from point 0.

Every other point starts at:

```
INT_MAX
```

When we add a point to the tree, we check all other points.

If connecting through the new point is cheaper:

```
minDist[j] = distance(point, j)
```

Then the min-heap gives us the next cheapest point to add.

Why do we need visited?

A point should only be added to the MST once.

```
visited[i] = true
```

means:

```
point i is already part of the tree.
```

If we pop a point that is already visited, skip it.

Complexity:

There are n points.

For every point we add, we check all other points.

Time:
O(n^2 log n)

Space:
O(n)

The main pattern to remember:

```
Prim's Algorithm

Start with one node
      |
      v
Find cheapest connection
      |
      v
Add new node
      |
      v
Update cheapest connections
      |
      v
Repeat until every node is included
```

The final answer is the total cost of all selected edges.
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        minDist[0] = 0;
        pq.push({ 0, 0 });
        int totalCost = 0;
        while (!pq.empty()) {
            auto [cost, curr] = pq.top();
            pq.pop();
            if (visited[curr]) {
                continue;
            }
            visited[curr] = true;
            totalCost += cost;
            for (int next = 0; next < n; next++) {
                if (visited[next]) {
                    continue;
                }
                int distance =abs(points[curr][0] - points[next][0]) +abs(points[curr][1] - points[next][1]);
                if (distance < minDist[next]) {
                    minDist[next] = distance;
                    pq.push({ distance, next });
                }
            }
        }
        return totalCost;
    }
};
