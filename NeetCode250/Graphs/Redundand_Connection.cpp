/*
Redundant Connection:

Use Union-Find, also called DSU.

The idea:

    If two nodes are already connected,
    adding an edge between them creates a cycle.

Union-Find keeps track of which nodes belong
to the same connected component.

For every edge [a, b]:

    If a and b are in different components:

        connect their components.

    If a and b are already in the same component:

        this edge creates a cycle.

        return this edge.

Example:

    1 -- 2
         |
         3 -- 4

After processing these edges:

    [1, 2]
    [2, 3]
    [3, 4]

all four nodes belong to the same component.

Now we see:

    [4, 1]

4 and 1 are already connected.

So adding [4, 1] creates:

    1 -- 2
    |    |
    4 -- 3

Therefore [4, 1] is redundant.

Union-Find uses two main operations:

    find(x):
        Finds the representative of x's component.

    unite(a, b):
        Merges the components containing a and b.

If:

    find(a) == find(b)

then a and b are already connected.

Important:

We process the edges from left to right.

The first edge that creates a cycle is the
redundant edge for this problem.

Time:
    O(E * alpha(V))

This is effectively O(E).

Space:
    O(V)

For the parent and rank arrays.
*/

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return false;
        }
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (!unite(a, b)) {
                return edge;
            }
        }
        return {};
    }
};