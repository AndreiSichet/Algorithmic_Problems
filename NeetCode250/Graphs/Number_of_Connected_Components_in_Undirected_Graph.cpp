/*
Number of Connected Components:

A connected component is a group of nodes where
every node can reach the other nodes in that group.

Example:

    0 -- 1 -- 2

    3 -- 4

    5

There are 3 connected components.

Use DFS.

Build an undirected graph.

For every edge:

    [a, b]

add:

    a -> b
    b -> a

Then go through every node.

If a node has not been visited:

    1. We found a new connected component.
    2. Increase the component count.
    3. Run DFS from that node.

The DFS marks every node belonging to that
component as visited.

When we find another unvisited node later,
it must belong to a different component.

Example:

    0 -- 1 -- 2

Starting at 0:

    DFS visits 0, 1, 2

So this is one component.

Next:

    3 -- 4

Starting at 3:

    DFS visits 3, 4

This is another component.

Finally:

    5

It has not been visited, so it is another
component by itself.

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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(graph, visited, i);
            }
        }
        return components;
    }
};