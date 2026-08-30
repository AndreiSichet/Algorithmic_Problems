/*
Course Schedule IV:

We need to answer many questions like:

    Is course 0 a prerequisite of course 3?

Prerequisites can be indirect.

Example:

    0 -> 1 -> 2 -> 3

Then:

    0 is a prerequisite of 1
    0 is a prerequisite of 2
    0 is a prerequisite of 3

We can think of the courses as a directed graph.

For:

    [a, b]

the edge is:

    a -> b

because a must be taken before b.

Use DFS from every course.

For each starting course i, DFS visits every
course that can be reached from i.

Store the result in:

    prereq[i][j]

If:

    prereq[i][j] == true

then course i is a prerequisite of course j.

Example:

    0 -> 1 -> 2

DFS from 0 visits:

    1
    2

So:

    prereq[0][1] = true
    prereq[0][2] = true

After calculating all reachable courses,
each query is just:

    prereq[u][v]

Time:
    O(V * (V + E))

We run DFS from every course.

Space:
    O(V^2 + V + E)

For the prerequisite matrix, graph, visited array,
and recursion stack.
*/

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& prereq, int node) {
        visited[node] = true;
        for (int next : graph[node]) {
            if (!visited[next]) {
                prereq[next] = true;
                dfs(graph, visited, prereq, next);
            }
        }
    }
    vector<bool> checkIfPrerequisite( int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);
        for (auto& prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];
            graph[a].push_back(b);
        }
        vector<vector<bool>> prereq( numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; i++) {
            vector<bool> visited(numCourses, false);
            dfs(graph, visited, prereq[i], i);
        }
        vector<bool> answer;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            answer.push_back(prereq[u][v]);
        }
        return answer;
    }
};