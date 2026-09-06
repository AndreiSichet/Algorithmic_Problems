/*
Reconstruct Flight Path:

This is an Eulerian path problem.

Think of:

```
airport = node
ticket = directed edge
```

The important part is that EVERY ticket must be used exactly once.

We use DFS.

However, we do not immediately add an airport to the result.

Instead:

```
1. Take the smallest available destination.
2. Remove that ticket from the graph.
3. DFS into that destination.
4. When there are no more tickets from the current airport,
   add the airport to the result.
```

This builds the answer backwards.

Example:

```
JFK -> NRT
NRT -> JFK
JFK -> KUL
```

DFS eventually reaches:

```
KUL
```

Then while returning:

```
result = [KUL]
result = [KUL, JFK]
result = [KUL, JFK, NRT]
result = [KUL, JFK, NRT, JFK]
```

Reverse it:

```
[JFK, NRT, JFK, KUL]
```

Why add the airport AFTER DFS?

Some airports can be dead ends.

For example:

```
JFK -> NRT
NRT -> JFK
JFK -> KUL
```

KUL has no outgoing tickets, so KUL must be at the end.

Adding airports after DFS naturally places these dead ends
at the end of the reversed result.

Lexicographically smallest:

From each airport, we always want to try the smallest
available destination first.

We use a min-heap for every airport.

```
graph["JFK"] -> smallest destination is on top
```

When we use a ticket, we remove it from the heap.

Important:

```
We remove TICKETS, not airports.
```

An airport can be visited multiple times.

Every ticket must be used exactly once.

Complexity:

Let E = number of tickets.

Building the graph:
O(E log E)

DFS:
O(E log E)

Space:
O(E)

The main pattern to remember:

```
while there are unused tickets:
    take smallest destination
    remove ticket
    DFS(destination)

result.push_back(current airport)

reverse(result)
```

*/

class Solution {
public:
    unordered_map<string, priority_queue<string,vector<string>,greater<string>>> graph;
    vector<string> result;
    void dfs(string airport) {
        while (!graph[airport].empty()) {
            string next = graph[airport].top();
            graph[airport].pop();
            dfs(next);
        }
        result.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            string from = ticket[0];
            string to = ticket[1];
            graph[from].push(to);
        }
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
