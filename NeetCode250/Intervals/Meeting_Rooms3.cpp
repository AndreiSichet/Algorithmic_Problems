/*
GREEDY + TWO MIN-HEAPS - MEETING ROOMS III

Goal:
- Assign meetings to n rooms according to the scheduling rules.
- Always use the available room with the lowest number.
- If all rooms are occupied, delay the meeting until a room becomes free.
- Delayed meetings must keep their original duration.
- Return the room that hosted the most meetings, breaking ties by lowest room number.

Key idea:
- Sort meetings by original start time.
- Use two min-heaps to track room availability:
  1. availableRooms: room numbers of currently unused rooms.
  2. occupiedRooms: pairs of (ending time, room number).
- The availableRooms heap ensures the lowest-numbered free room is chosen.
- The occupiedRooms heap ensures the room that becomes free earliest is
  processed first. If multiple rooms become free at the same time, choose
  the room with the lowest number.
- If every room is occupied, delay the meeting until the earliest room frees.
  Its new ending time is the earliest available time plus the original duration.

Algorithm:
1. Sort meetings by original start time.
2. Initialize availableRooms with all room numbers from 0 to n - 1.
3. Initialize occupiedRooms as a min-heap of (endTime, roomNumber).
4. Initialize a count array to track how many meetings each room hosts.
5. For each meeting [start, end]:
   - While the earliest occupied meeting ends at or before start:
       Release its room by moving its room number into availableRooms.
   - If availableRooms is not empty:
       Assign the meeting to the lowest-numbered available room.
       Its ending time remains end.
   - Otherwise:
       The meeting must be delayed.
       Take the room with the earliest ending time, breaking ties by
       lowest room number.
       The new meeting starts when that room becomes free.
       Its new ending time is that start time plus (end - start).
       Reuse the room immediately.
   - Increment the meeting count for the assigned room.
   - Push (newEndTime, roomNumber) into occupiedRooms.
6. Find the room with the largest meeting count.
   If counts are equal, keep the room with the lowest number.

Why this works:
- Sorting by original start time ensures meetings are considered in the
  required priority order, even when some meetings are delayed.
- The availableRooms min-heap always selects the lowest-numbered free room.
- When no room is available, the occupiedRooms min-heap selects the room
  that becomes free first, breaking ties by room number.
- Delaying a meeting preserves its duration because its new end time is
  calculated as newStart + (originalEnd - originalStart).
- Counting each assignment and scanning rooms in ascending order gives
  the most-used room, with the correct tie-breaking rule.

Important boundaries:
- Release rooms while endTime <= start, not just endTime < start.
  Meetings use half-open intervals [start, end), so a room ending at time 8
  is available for a meeting starting at time 8.
- When all rooms are occupied, do not discard the original duration.
- Process meetings by original start time, not by their delayed start time.
- For occupiedRooms, store pairs as (endTime, roomNumber) so ties are
  automatically resolved by the lowest room number.
- For the final answer, scan room numbers from 0 upward and update only
  when a strictly larger count is found.

Complexity:
- Time: O(m log m + m log n + n), where m is the number of meetings.
  Sorting costs O(m log m), and each meeting requires heap operations
  costing O(log n). Initializing and scanning rooms costs O(n).
- Space: O(m + n) for the sorted meetings, heaps, and count array.
*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> occupiedRooms;
        vector<int> count(n, 0);
        for (int room = 0; room < n; room++)
            availableRooms.push(room);
        for (const auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }
            int room;
            long long newEnd;
            if (!availableRooms.empty()) {
                room = availableRooms.top();
                availableRooms.pop();
                newEnd = end;
            }
            else {
                auto earliest = occupiedRooms.top();
                occupiedRooms.pop();
                room = earliest.second;
                newEnd = earliest.first + duration;
            }
            count[room]++;
            occupiedRooms.push({ newEnd, room });
        }
        int result = 0;
        for (int room = 1; room < n; room++) {
            if (count[room] > count[result])
                result = room;
        }
        return result;
    }
};