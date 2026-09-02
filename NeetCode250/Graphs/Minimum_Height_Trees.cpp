/*
Problem:

Find all nodes that can be used as roots to produce
a tree with minimum height.

Key idea:

The optimal root of a tree is always its center.

A tree can have either one center or two centers.
We find them by repeatedly removing all current leaves.

Visual:

0 - 1 - 2 - 3 - 4

Remove leaves:
0               4

Remaining:
1 - 2 - 3

Remove leaves:
1               3

Remaining:
2

The remaining node(s) are the answer.

Rules:

1. Build the adjacency list.
2. Store the degree of every node.
3. Put every node with degree 1 into the queue.
4. Remove all current leaves as one layer.
5. Decrease the degree of their neighbors.
6. If a neighbor becomes a leaf, add it to the queue.
7. Continue until at most 2 nodes remain.
8. The remaining nodes are the MHT roots.

The remaining count is important because the queue can contain
the leaves of the next layer while we are processing the current layer.

Time:
    O(n)

Space:
    O(n)
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n,vector<vector<int>>& edges) {
        if (n == 1) {
            return { 0 };
        }
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        int remaining = n;
        while (remaining > 2) {
            int leaves = q.size();
            remaining -= leaves;
            for (int i = 0; i < leaves; i++) {
                int leaf = q.front();
                q.pop();
                for (int neighbor : graph[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};