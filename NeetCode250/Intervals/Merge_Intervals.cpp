
/*
SORTING + GREEDY - MERGE INTERVALS

Goal:
- Merge all overlapping intervals.
- Return intervals that are sorted and non-overlapping.

Key idea:
- Sort intervals by their start value.
- Once sorted, an interval can only overlap with the last interval
  added to the result.
- Compare the current interval with the last merged interval.

Algorithm:
1. Sort intervals by start in ascending order.
2. Initialize the result with the first interval.
3. For each remaining interval [start, end]:
   - Let `last` be the last interval in the result.
   - If start <= last[1], they overlap:
       last[1] = max(last[1], end)
     Extend the last interval to cover both intervals.
   - Otherwise:
       Add the current interval to the result as a new interval.
4. Return the result.

Why sorting works:
- After sorting, intervals are processed from left to right.
- If the current interval starts after the last merged interval ends,
  it cannot overlap with any earlier result interval.
- If it starts at or before the last interval's end, they overlap and
  can be merged.
- Use max() for the end because the current interval may be contained
  inside the last interval or extend beyond it.

Important boundary:
- Use start <= last[1], not start < last[1].
- Intervals sharing an endpoint overlap in this problem.
  Example: [1,2] and [2,3] merge into [1,3].

Example:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Sorted:
[[1,3],[2,6],[8,10],[15,18]]

- [2,6] overlaps [1,3] -> merge into [1,6].
- [8,10] does not overlap [1,6] -> add it.
- [15,18] does not overlap [8,10] -> add it.

Result:
[[1,6],[8,10],[15,18]]

Complexity:
- Time: O(n log n) for sorting, then O(n) for merging.
- Extra space: O(n) for the result, excluding sorting overhead.
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (auto& interval : intervals) {
            if (result.empty() || interval[0] > result.back()[1]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};