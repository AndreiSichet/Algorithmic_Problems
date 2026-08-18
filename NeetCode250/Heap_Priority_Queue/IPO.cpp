/*
IPO:

Goal:
    Complete at most k projects and maximize capital.

Each project:
    capital[i] = minimum capital required
    profits[i] = profit gained after completing it

Main idea:
    At any moment, add every project that we can afford into a max heap.
    Then choose the project with the largest profit.

Why?

    If multiple projects are affordable, choosing the one
    with the largest profit gives us the most capital,
    which can unlock even more projects.

Data structures:

    1. Sort projects by required capital.

    2. Max heap:
           stores profits of projects currently affordable.

Example:

    w = 0

    projects:
        capital = 0, profit = 1
        capital = 1, profit = 5
        capital = 2, profit = 3

    Initially:
        w = 0

    Can afford:
        profit 1

    Take it:
        w = 1

    Now can afford:
        profit 5

    Take it:
        w = 6

    Now can afford:
        profit 3

Important:
    Each project can only be selected once.

Algorithm:

    Sort projects by capital.

    For i = 1 to k:

        Add all projects with:
            capital[i] <= current capital

        into max heap.

        If heap is empty:
            no project can be started
            -> stop.

        Take project with maximum profit.

        current capital += maximum profit.

Time:
    O(n log n + k log n)

Space:
    O(n)
*/

class Solution {
public:
    int findMaximizedCapital(int k,int w,vector<int>& profits,vector<int>& capital) {
        int n = profits.size();
        // {required capital, profit}
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i],profits[i]});
        }
        // Sort by required capital.
        sort(projects.begin(), projects.end());
        // Maximum profit among affordable projects.
        priority_queue<int> maxHeap;
        int i = 0;
        // We can complete at most k projects.
        for (int project = 0; project < k; project++) {
            // Add every project we can currently afford.
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            // No affordable project.
            if (maxHeap.empty()) {
                break;
            }
            // Take the most profitable affordable project.
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};