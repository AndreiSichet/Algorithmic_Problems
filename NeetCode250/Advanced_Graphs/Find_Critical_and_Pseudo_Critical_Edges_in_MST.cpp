
/*
Problem:

Find which edges are critical or pseudo-critical in the MST.

Key idea:

1. Build the normal MST and store its total weight.
2. For every edge:
   - Exclude it and build an MST again.
     If the MST becomes more expensive or impossible, the edge is critical.
   - Force it into the MST first, then complete the MST with Kruskal.
     If the total weight equals the normal MST weight, the edge is pseudo-critical.

Kruskal:

- Sort edges by weight.
- Use Union-Find to detect cycles.
- If two vertices are in different components, unite them and add the edge.

Why force an edge?

If an edge can be included while still producing an MST with the same
minimum total weight, then that edge can appear in at least one MST.

Why exclude an edge?

If removing an edge makes the best possible spanning tree more expensive,
then every MST must contain that edge.

Time:
    O(E^2 log E)

Space:
    O(E + V)
*/

class Solution {
public:
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return false;
            }
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            return true;
        }
    };
    int kruskal(int n,vector<vector<int>>& edges,int skip,int force) {
        DSU dsu(n);
        int cost = 0;
        int edgesUsed = 0;
        if (force != -1) {
            int a = edges[force][1];
            int b = edges[force][2];
            int weight = edges[force][0];
            dsu.unite(a, b);
            cost += weight;
            edgesUsed++;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip || i == force) {
                continue;
            }
            int a = edges[i][1];
            int b = edges[i][2];
            int weight = edges[i][0];
            if (dsu.unite(a, b)) {
                cost += weight;
                edgesUsed++;
                if (edgesUsed == n - 1) {
                    break;
                }
            }
        }
        if (edgesUsed != n - 1) {
            return INT_MAX;
        }
        return cost;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,vector<vector<int>>& edges) {
        vector<vector<int>> sortedEdges;
        for (int i = 0; i < edges.size(); i++) {
            sortedEdges.push_back({
                edges[i][2],
                edges[i][0],
                edges[i][1],
                i
                });
        }
        sort(sortedEdges.begin(), sortedEdges.end());
        int mstWeight = kruskal(n, sortedEdges, -1, -1);
        vector<int> critical;
        vector<int> pseudoCritical;
        for (int i = 0; i < sortedEdges.size(); i++) {
            int originalIndex = sortedEdges[i][3];
            int withoutEdge = kruskal(n,sortedEdges,i,-1);
            if (withoutEdge > mstWeight) {
                critical.push_back(originalIndex);
                continue;
            }
            int withEdge = kruskal(n,sortedEdges,-1,i);
            if (withEdge == mstWeight) {
                pseudoCritical.push_back(originalIndex);
            }
        }
        return { critical, pseudoCritical };
    }
};
