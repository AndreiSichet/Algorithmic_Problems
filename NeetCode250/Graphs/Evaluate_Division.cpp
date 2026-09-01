```cpp
/*
Evaluate Division:

Think of every variable as a node in a graph.

For an equation:

    a / b = 2

create two directed edges:

    a -> b with weight 2
    b -> a with weight 1 / 2

The weight represents the division between
the two variables.

Example:

    a / b = 2
    b / c = 3

Graph:

    a --2--> b --3--> c
    a <--0.5-- b <--1/3-- c

To answer:

    a / c

find a path from a to c:

    a -> b -> c

Multiply the edge weights:

    2 * 3 = 6

So:

    a / c = 6

For every query, use DFS to find a path
from the first variable to the second.

During DFS:

    current / neighbor = edge weight

If:

    current / target = result

then:

    start / target =
    (start / current) * (current / target)

So we multiply the weights along the path.

If either variable does not exist, return -1.

If both variables exist but there is no path
between them, return -1.

A visited set is necessary because the graph
can contain cycles.

Example:

    a -> b -> c -> a

Without visited, DFS could loop forever.

Time:

    Building graph: O(E)

    Each query: O(V + E)

Space:

    O(V + E)

where V is the number of variables and
E is the number of equations.
*/

class Solution {
public:
    bool dfs(string curr,string target,unordered_map<string, vector<pair<string,double>>>& graph, unordered_set<string>& visited,double product,double& result) {
        if (curr == target) {
            result = product;
            return true;
        }
        visited.insert(curr);
        for (auto& [next, weight] : graph[curr]) {
            if (visited.count(next)) {
                continue;
            }
            if (dfs(next,target,graph,visited,product * weight,result)) {
                return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,vector<double>& values,vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];
            graph[a].push_back({ b, value });
            graph[b].push_back({ a, 1.0 / value });
        }
        vector<double> result;
        for (auto& query : queries) {
            string start = query[0];
            string target = query[1];
            if (!graph.count(start) || !graph.count(target)) {
                result.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double answer = -1.0;
            dfs(start,target,graph,visited,1.0,answer);
            result.push_back(answer);
        }
        return result;
    }
};
