/*
Graph Valid Tree:

A graph is a valid tree if:

    1. It is connected.
    2. It contains no cycles.

For an undirected graph with n nodes,
a tree must have exactly:

    n - 1 edges

So first check:

    edges.size() == n - 1

If there are more edges:

    There must be a cycle.

If there are fewer edges:

    The graph cannot be connected.

After this check, we only need to verify
that every node is connected.

Build an undirected graph.

For every edge:

    [a, b]

add:

    a -> b
    b -> a

Then run DFS starting from node 0.

Keep a visited array.

If DFS visits every node, the graph is connected.

Because we already know there are exactly n - 1
edges, a connected graph cannot contain a cycle.

Therefore:

    n - 1 edges + connected = valid tree

Example:

    0 -- 1 -- 2
         |
         3

n = 4
edges = 3

DFS from 0 visits:

    0 -> 1 -> 2
         |
         -> 3

All 4 nodes are visited.

Therefore this is a valid tree.

Time:
    O(V + E)

V = number of nodes
E = number of edges

Space:
    O(V + E)

For the graph, visited array, and recursion stack.
*/

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        dfs(graph, visited, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};