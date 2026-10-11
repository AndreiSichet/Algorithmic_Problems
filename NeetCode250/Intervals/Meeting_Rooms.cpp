
/*
SORTING + GREEDY - MEETING ROOMS

Goal:
- Determine whether all meetings can be attended without conflicts.
- Meetings may be given in any order.
- Meetings sharing an endpoint are allowed: (0,8) and (8,10).

Key idea:
- Sort meetings by start time.
- After sorting, only the previous meeting's end needs to be checked
  against the current meeting's start.

Algorithm:
1. Sort intervals by start time in ascending order.
2. Initialize `end` to the end time of the first meeting.
3. Scan the remaining meetings:
   - If intervals[i].start >= end:
       No conflict. Update end = intervals[i].end.
   - Otherwise:
       The current meeting starts before the previous meeting ends.
       A conflict exists, so return false.
4. If every meeting passes the check, return true.

Why sorting works:
- Meetings are processed chronologically.
- Since start times are sorted, if the current meeting starts before
  the previous meeting ends, they overlap.
- If it starts at or after the previous end, there is no conflict.
- Updating `end` keeps track of the end of the most recently checked
  meeting.

Important boundary:
- Use start >= end, not start > end.
- A meeting starting exactly when another ends is allowed.

Complexity:
- Time: O(n log n) for sorting, then O(n) for checking.
- Extra space: O(1) auxiliary space, excluding sorting overhead.
*/
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }
        return true;
    }
};