
/*
Problem:

Build a k x k matrix containing every number from 1 to k exactly once.

rowConditions:
    [a, b] means a must be above b.

colConditions:
    [a, b] means a must be left of b.

Key idea:

Treat row conditions and column conditions as two separate directed graphs.

For both graphs:
    - Build edges a -> b.
    - Run topological sort.
    - If a cycle exists, return an empty matrix.

The row topological order tells us the row of each number.
The column topological order tells us the column of each number.

Then place every number using:
    matrix[rowPos[num]][colPos[num]] = num.

Time:
    O(k + n + m)

Space:
    O(k + n + m)
*/

class Solution {
public:
    vector<int> topoSort(int k,vector<vector<int>>& conditions) {
        vector<vector<int>> graph(k + 1);
        vector<int> indegree(k + 1, 0);
        for (auto& condition : conditions) {
            int a = condition[0];
            int b = condition[1];
            graph[a].push_back(b);
            indegree[b]++;
        }
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int next : graph[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (order.size() != k) {
            return {};
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k,vector<vector<int>>& rowConditions,vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);
        if (rowOrder.empty() || colOrder.empty()) {
            return {};
        }
        vector<int> rowPos(k + 1);
        vector<int> colPos(k + 1);
        for (int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }
        vector<vector<int>> matrix(k,vector<int>(k, 0));
        for (int num = 1; num <= k; num++) {
            matrix[rowPos[num]][colPos[num]] = num;
        }
        return matrix;
    }
};
