/*
Task Scheduler:

Need to schedule tasks so identical tasks have at least n cycles between them.

Use:
    1. Max heap
       Stores remaining frequency of each task.
       Highest frequency is always on top.

    2. Queue
       Stores tasks that are cooling down.

Each queue entry stores:
    {remainingCount, availableTime}

For every CPU cycle:
    1. If a task becomes available, put it back
       into the max heap.

    2. If heap is not empty:
           take the task with highest frequency
           execute it
           decrease its count

           if it still has remaining copies:
               put it in cooldown queue

    3. If heap is empty:
           CPU must be idle.

Example:
    tasks = [A,A,A,B,B,B]
    n = 2

Schedule:

    A B idle A B idle A B

Same tasks have 2 cycles between them.

Answer = 8.

Main idea:
    Max heap chooses the task we most need to schedule.
    Queue handles the cooldown period.

Time: O(N log 26)
    There are at most 26 different tasks.

Space: O(26)
*/

class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        // Count frequency of each task.
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }
        // Max heap: highest remaining frequency first.
        priority_queue<int> maxHeap;
        for (int freq : count) {
            if (freq > 0) {
                maxHeap.push(freq);
            }
        }
        // {remaining count, time when task can be used again}
        queue<pair<int, int>> cooldown;
        int time = 0;
        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;
            // Move tasks whose cooldown is finished
            // back into the heap.
            if (!cooldown.empty() && cooldown.front().second == time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }
            // Execute the task with highest frequency.
            if (!maxHeap.empty()) {
                int remaining = maxHeap.top();
                maxHeap.pop();
                remaining--;
                // If copies remain, put task into cooldown.
                if (remaining > 0) {
                    cooldown.push({remaining,time + n + 1});
                }
            }
        }
        return time;
    }
};