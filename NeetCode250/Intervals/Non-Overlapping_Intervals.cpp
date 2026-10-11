
/*
GREEDY + SORTING - NON-OVERLAPPING INTERVALS

Goal:
- Remove the minimum number of intervals so that none overlap.
- Intervals sharing an endpoint are allowed, e.g. [1,2] and [2,3].

Key idea:
- Keep as many intervals as possible and remove the rest.
- Sort intervals by their END time in ascending order.
- Always keep the interval that ends earliest among the available choices.
- Ending earlier leaves the most room for future intervals.

Algorithm:
1. Sort intervals by end time in ascending order.
2. Keep the first interval:
     end = intervals[0][1]
   This is the earliest-ending interval.
3. Scan the remaining intervals:
   - If intervals[i][0] >= end:
       The interval starts at or after the previous kept interval ends.
       Keep it and update end = intervals[i][1].
   - Otherwise:
       It overlaps the previous kept interval, so remove it.
       Increment removals.
4. Return removals.

Why greedy works:
- When two intervals overlap, keeping the one that ends earlier is
  always at least as good as keeping the one that ends later.
- The earlier end cannot block any interval that the later end would allow.
- Repeating this choice maximizes the number of intervals kept.
- Therefore:
    minimum removals = total intervals - maximum intervals kept.

Important boundary:
- Use start >= end to allow intervals sharing an endpoint.
- Example: [1,2] and [2,3] are compatible.

Example:
intervals = [[1,2],[2,3],[3,4],[1,3]]

Sorted by end:
[[1,2],[2,3],[1,3],[3,4]]

Keep [1,2].
Keep [2,3] because 2 >= 2.
Remove [1,3] because 1 < 3.
Keep [3,4] because 3 >= 3.

One interval removed -> answer = 1.

Complexity:
- Time: O(n log n) for sorting, then O(n) for scanning.
- Extra space: O(1) auxiliary space, excluding sorting overhead.
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });
        int removals = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
            }
            else {
                removals++;
            }
        }
        return removals;
    }
};