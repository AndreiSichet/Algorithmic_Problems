
/*
GREEDY + MIN-HEAP - MEETING ROOMS II

Goal:
- Find the minimum number of rooms needed so all meetings can take place.
- Meetings that overlap must use different rooms.
- Meetings sharing an endpoint do not overlap.

Key idea:
- Sort meetings by start time.
- Track the end times of meetings currently assigned to rooms using a min-heap.
- The heap's top is the earliest time any room becomes available.
- Reuse that room if it is free before or exactly when the next meeting starts.
- Otherwise, allocate another room.

Algorithm:
1. Sort meetings by start time.
2. Create a min-heap of meeting end times.
   Each heap entry represents a room's current meeting end time.
3. For each meeting [start, end]:
   - If the heap is not empty and heap.top() <= start:
       A room is available.
       Remove its previous meeting end time from the heap.
   - Push the current meeting's end time into the heap.
4. After processing each meeting, the heap contains one end time per
   room currently in use.
5. The maximum heap size is the minimum number of rooms required.
   Because rooms are reused whenever possible, the final heap size also
   gives the answer.

Why this works:
- Meetings are processed in chronological start order.
- The earliest-ending room is the best room to reuse.
- If its end time is greater than the next start time, every room is
  still occupied, so a new room is necessary.
- If its end time is <= the next start time, at least one room can be reused.

Important boundary:
- Use heap.top() <= start, not heap.top() < start.
- A meeting ending at time 8 frees its room for a meeting starting at 8.

Complexity:
- Time: O(n log n) for sorting and heap operations.
- Space: O(n) for the heap.
*/
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (const auto& meeting : intervals) {
            if (!minHeap.empty() && minHeap.top() <= meeting.start)
                minHeap.pop();
            minHeap.push(meeting.end);
        }
        return minHeap.size();
    }
};