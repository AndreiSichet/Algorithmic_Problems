/*
Single Threaded CPU:

Each task:
    [enqueueTime, processingTime]

We need to simulate the CPU.

First:
    Sort tasks by enqueueTime.

For each task store:
    {enqueueTime, processingTime, originalIndex}

Use a min heap for AVAILABLE tasks.

Heap priority:
    1. smallest processingTime
    2. smallest originalIndex

Algorithm:

    Sort all tasks by enqueueTime.

    time = 0
    i = 0

    While there are tasks left:

        If heap is empty:
            CPU is idle.
            Jump time to the next task's enqueueTime.

        Add every task whose enqueueTime <= time
        into the heap.

        Take the task with:
            smallest processingTime
            and smallest index if tied.

        Add its index to the answer.

        Process it:
            time += processingTime.

Main idea:

    Sorted array tells us:
        "Which tasks have arrived?"

    Min heap tells us:
        "Which available task should run next?"

Example:

    tasks = [[1,2], [2,4], [3,2], [4,1]]

    Sort by enqueue time:

        time 1: task 0 -> processing 2
        time 2: task 1 -> processing 4
        time 3: task 2 -> processing 2
        time 4: task 3 -> processing 1

    time = 1
    available:
        task 0

    run task 0
    time = 3

    At time 3:
        task 1 and task 2 are available

    heap:
        task 2 -> processing 2
        task 1 -> processing 4

    run task 2
    time = 5

    At time 5:
        task 1 and task 3 are available

    heap:
        task 3 -> processing 1
        task 1 -> processing 4

    run task 3
    then task 1.

Time Complexity:
    Sorting: O(n log n)
    Each task enters/leaves heap once: O(n log n)
    Total: O(n log n)

Space Complexity:
    O(n)
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // {enqueueTime, processingTime, originalIndex}
        vector<array<int, 3>> sortedTasks;
        for (int i = 0; i < n; i++) {
            sortedTasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        // Sort by enqueue time.
        sort(sortedTasks.begin(), sortedTasks.end());
        /*
        Min heap:
            first  = processing time
            second = original index

        pair automatically compares:
            processing time first,
            then index.
        */
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> minHeap;
        vector<int> result;
        long long time = 0;
        int i = 0;
        while (i < n || !minHeap.empty()) {
            // If no task is available, jump to
            // the next task's enqueue time.
            if (minHeap.empty() && time < sortedTasks[i][0]) {
                time = sortedTasks[i][0];
            }
            // Add all tasks that have arrived.
            while (i < n && sortedTasks[i][0] <= time) {
                int processingTime = sortedTasks[i][1];
                int index = sortedTasks[i][2];
                minHeap.push({processingTime,index});
                i++;
            }
            // Choose the available task with:
            // 1. shortest processing time
            // 2. smallest index if tied
            auto [processingTime, index] = minHeap.top();
            minHeap.pop();
            result.push_back(index);
            // Process the task completely.
            time += processingTime;
        }
        return result;
    }
};