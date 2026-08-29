/*
Course Schedule II:

This is the same topological sorting idea as
Course Schedule.

The difference is:

    Course Schedule:
        We only need to know if we can finish.

    Course Schedule II:
        We need to return the actual course order.

Use Kahn's Algorithm with BFS.

For:

    [a, b]

we have:

    b -> a

because b must be taken before a.

indegree[course] tells us how many prerequisites
that course still has.

Start by putting every course with:

    indegree == 0

into the queue.

These courses can be taken immediately.

Then:

    1. Take a course from the queue.
    2. Add it to the answer.
    3. Remove it as a prerequisite from its neighbors.
    4. If a neighbor now has indegree 0,
       add it to the queue.

Continue until the queue is empty.

IMPORTANT:

Do NOT check whether all courses were processed
inside the while loop.

The while loop needs to finish first.

After BFS:

    if ans.size() == numCourses

then every course was processed, so we have
a valid ordering.

Otherwise, some courses could not be processed.

That means there is a cycle, so return an empty
array.

Example:

    0 -> 1 -> 2

BFS gives:

    [0, 1, 2]

This is a valid order because every prerequisite
appears before the course that needs it.

If there is a cycle:

    0 -> 1 -> 2 -> 0

no course in the cycle has indegree 0.

So those courses cannot be added to the answer.

Therefore:

    ans.size() < numCourses

and we return an empty array.

Time:
    O(V + E)

V = number of courses
E = number of prerequisites

Space:
    O(V + E)

For the graph, indegree array, queue, and answer.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& a : prerequisites) {
            int course = a[0];
            int pre = a[1];
            graph[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (int next : graph[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (ans.size() == numCourses) {
            return ans;
        }
        return {};
    }
};