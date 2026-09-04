/*
Problem:
Network Delay Time

We have n nodes and directed edges:
times[i] = {from, to, time}

A signal starts at node k and travels through the network.

We need the minimum amount of time needed for ALL nodes to receive
the signal.

Key idea:
Use Dijkstra's algorithm.

dist[i] = minimum time needed for the signal to reach node i.

The graph is directed, so:
from -> to

Example:
1 --4--> 2
1 --2--> 3
3 --5--> 4

If k = 1:
dist[1] = 0
dist[2] = 4
dist[3] = 2
dist[4] = 7

The answer is NOT the minimum distance.

The signal travels to all nodes simultaneously.

Therefore, we need to wait until the LAST node receives
the signal.

answer = maximum dist[i]

If any node has distance INT_MAX, that node cannot be reached,
so return -1.

Dijkstra process:

1. Build the graph.
2. Set every distance to INT_MAX.
3. Set dist[k] = 0.
4. Put {0, k} into a min-heap.
5. Take the node with the smallest distance.
6. Check all of its neighbors.
7. Try to improve their distances:
   newDist = distance + edgeTime
8. If newDist is smaller:
   update dist
   push the new pair into the heap
9. After Dijkstra finishes:
   if any node is unreachable -> return -1
   otherwise return the maximum distance

Why use a min-heap?

Dijkstra always processes the currently known closest node first.

The priority queue stores:
{distance, node}

The greater comparator makes it a min-heap.

Why do we check this?

```
if (distance > dist[node])
    continue;
```

A node can be pushed into the priority queue multiple times.

Example:
first we find node 3 with distance 10
later we find node 3 with distance 5

The heap can contain both:
{5, 3}
{10, 3}

When {5, 3} is processed, dist[3] becomes 5.

Later {10, 3} is popped, but it is outdated because:
10 > dist[3]

So we skip it.

Why is the answer the maximum distance?

Dijkstra gives the minimum arrival time for EACH node.

But we need the minimum time for ALL nodes.

If:
dist = [0, 4, 2, 7]

Then:
node 1 receives at 0
node 2 receives at 4
node 3 receives at 2
node 4 receives at 7

All nodes have received the signal at time 7.

Therefore:
answer = max(dist)

Complexity:
Let V = number of nodes
Let E = number of edges

Time:
O((V + E) log V)

Space:
O(V + E)
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
            for (auto& path : times) {
                int from = path[0];
                int to = path[1];
                int time = path[2];
                graph[from].push_back({ to, time });
            }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<tuple<int, int>,vector<tuple<int, int>>,greater<tuple<int, int>>> pq;
        dist[k] = 0;
        pq.push({ 0, k });
        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();
            if (distance > dist[node]) {
                continue;
            }
            for (auto [next, time] : graph[node]) {
                int newDist = distance + time;
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    pq.push({ newDist, next });
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
