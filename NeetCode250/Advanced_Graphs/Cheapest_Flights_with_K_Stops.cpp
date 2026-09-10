/*
Cheapest Flights Within K Stops:

We need the cheapest path from src to dst,
but we can use at most k stops.

At most k stops means:

```
at most k + 1 flights
```

This is a shortest path problem with an additional
limit on the number of edges.

We can use a Bellman-Ford style approach.

dist[i] means:

```
cheapest price currently known to reach airport i
```

Initially:

```
dist[src] = 0
all other airports = INT_MAX
```

We then relax every flight.

For a flight:

```
from -> to with price
```

we try:

```
dist[to] = min(dist[to], dist[from] + price)
```

But we only perform this process k + 1 times.

Why k + 1?

Each iteration represents using one more flight.

```
1 iteration = at most 1 flight
2 iterations = at most 2 flights
...
k + 1 iterations = at most k + 1 flights
```

Since k stops means k + 1 flights,
this gives us exactly the allowed number of flights.

IMPORTANT:

Use a copy of dist for every iteration.

Example:

```
vector<int> nextDist = dist;
```

Then use nextDist for updates.

Why?

Suppose we update dist during the same iteration.

That new value could immediately be used by another
edge, allowing multiple flights in one iteration.

Using a copy ensures that every iteration adds
at most ONE flight.

Example:

```
src -> A -> B
```

During iteration 1:

```
src -> A
```

During iteration 2:

```
A -> B
```

This correctly limits the number of flights.

At the end:

```
if dist[dst] == INT_MAX
    return -1

otherwise return dist[dst]
```

Complexity:

Let:
V = number of airports
E = number of flights

We process all flights k + 1 times.

Time:
O(k * E)

Space:
O(V)

Main pattern:

```
dist[src] = 0

repeat k + 1 times:
    copy dist
    relax every flight

return dist[dst]
```

*/

class Solution {
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            vector<int> nextDist = dist;
            for (auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                if (dist[from] == INT_MAX) {
                    continue;
                }
                nextDist[to] = min(nextDist[to],dist[from] + price);
            }
            dist = nextDist;
        }
        if (dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};
