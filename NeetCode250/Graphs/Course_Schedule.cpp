/*
Course Schedule:

Treat the courses as a directed graph.

For:

    [a, b]

we have:

    b -> a

because b must be taken before a.

The problem is possible if and only if the graph
does not contain a cycle.

Example:

    0 -> 1 -> 2

This is possible.

But:

    0 -> 1 -> 2 -> 0

is impossible because every course in the cycle
depends on another course in the same cycle.

Use Kahn's Algorithm.

This is a BFS approach to topological sorting.

First, calculate the indegree of every course.

Indegree means:

    number of prerequisites for this course

Example:

    0 -> 1
    0 -> 2

Then:

    indegree[0] = 0
    indegree[1] = 1
    indegree[2] = 1

Courses with indegree 0 can be taken immediately.

Put all of them into the queue.

Then:

    1. Take a course from the queue.
    2. Count it as completed.
    3. Remove it as a prerequisite from
       all courses that depend on it.
    4. If a course now has indegree 0,
       add it to the queue.

If we can process all courses:

    return true

If some courses cannot be processed:

    return false

Those remaining courses must be part of a cycle.

Time:
    O(V + E)

V = number of courses
E = number of prerequisites

Space:
    O(V + E)

For the graph, indegree array, and queue.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prereq = prerequisite[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int course = 0; course < numCourses; course++) {
            if (indegree[course] == 0) {
                q.push(course);
            }
        }
        int completed = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            completed++;
            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return completed == numCourses;
    }
};