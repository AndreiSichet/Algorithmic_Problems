
/*
INTERVALS - INSERT INTERVAL

Goal:
- Insert newInterval into a sorted list of non-overlapping intervals.
- Merge any intervals that overlap with newInterval.
- Return the sorted, non-overlapping result.

Key idea:
- Since intervals are already sorted, process them in three phases:
  1. Intervals completely before newInterval.
  2. Intervals overlapping newInterval.
  3. Intervals completely after newInterval.

Algorithm:
1. Initialize an empty result array and index i = 0.

2. Add intervals before newInterval:
   - While intervals[i][1] < newInterval[0], the current interval ends
     before newInterval starts.
   - Add it directly to the result because it cannot overlap.
   - Increment i.

3. Merge overlapping intervals:
   - While intervals[i][0] <= newInterval[1], the current interval starts
     before or at the end of newInterval.
   - Expand newInterval to include it:
       start = min(start, intervals[i][0])
       end = max(end, intervals[i][1])
   - Increment i.
   - Continue because expanding the interval may cause it to overlap
     with additional intervals.

4. Add the merged newInterval to the result.

5. Add all remaining intervals:
   - They start after the merged interval ends, so they cannot overlap.
   - Append them directly.

Why this works:
- The original intervals are sorted and non-overlapping.
- Therefore, intervals before the new interval never need merging.
- Every overlapping interval can be absorbed by expanding the new interval.
- Once an interval starts after the merged end, all following intervals
  are also after it.

Important boundary conditions:
- Use intervals[i][1] < start for intervals strictly before the new interval.
- Use intervals[i][0] <= end for overlapping intervals.
- Equality counts as overlap under the standard Insert Interval problem.

Complexity:
- Time: O(n), since each interval is processed once.
- Extra space: O(n) for the result.
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};