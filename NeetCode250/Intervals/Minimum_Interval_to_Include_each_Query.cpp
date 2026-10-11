/*
SORTING + MIN-HEAP - MINIMUM INTERVAL TO INCLUDE EACH QUERY

Goal:
- For each query point, find the length of the shortest interval containing it.
- An interval [left, right] contains query if left <= query <= right.
- Return -1 if no interval contains the query.
- Preserve the original order of queries in the output.

Key idea:
- Sort intervals by their left endpoint.
- Process queries in ascending order, but remember their original indices.
- Use a min-heap ordered by interval length.
- For each query, add every interval that has started.
- Remove intervals that have already ended before the query.
- The shortest remaining interval in the heap is the answer.

Algorithm:
1. Sort intervals by their left endpoint.
2. Store each query with its original index as (query, index).
3. Sort these query pairs by query value.
4. Initialize a min-heap storing (intervalLength, rightEndpoint).
   The heap prioritizes the shortest interval.
5. Maintain a pointer i to the next interval to process.
6. For each query in ascending order:
   - Add every interval whose left endpoint <= query:
       Calculate its length as right - left + 1.
       Push (length, right) into the min-heap.
       Advance i.
   - While the heap is not empty and its top interval has right < query:
       Remove it because it cannot contain the current query.
   - If the heap is not empty:
       The top interval is the shortest valid interval.
       Store its length at the query's original index.
     Otherwise:
       Store -1.
7. Return the result array.

Why this works:
- Queries are processed in ascending order, so intervals are added
  exactly when their left endpoints become eligible.
- Every interval in the heap has a left endpoint <= the current query.
- Removing intervals with right < query ensures that every remaining
  interval contains the current query.
- The min-heap places the shortest interval first, so its top gives
  the optimal answer whenever a valid interval exists.
- Original query indices ensure that sorting queries does not change
  the order of the returned answers.

Important boundaries:
- Intervals are inclusive, so an interval is valid when right >= query.
- Remove intervals only when right < query, not right <= query.
- Interval length is right - left + 1.
- Use the original query index when storing each answer.
- The heap may contain expired intervals that are not at its top.
  This is safe: expired intervals are removed whenever they reach the top,
  and cannot affect the shortest valid answer while buried beneath
  shorter valid intervals.

Complexity:
- Time: O(n log n + q log q + (n + q) log n),
  where n is the number of intervals and q is the number of queries.
  Sorting and heap operations dominate the running time.
- Space: O(n + q) for the query pairs, heap, and output array.
*/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++)
            sortedQueries.push_back({ queries[i], i });
        sort(sortedQueries.begin(), sortedQueries.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> result(queries.size(), -1);
        int i = 0;
        for (const auto& [query, index] : sortedQueries) {
            while (i < intervals.size() && intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                int length = right - left + 1;
                minHeap.push({ length, right });
                i++;
            }
            while (!minHeap.empty() && minHeap.top().second < query)
                minHeap.pop();
            if (!minHeap.empty())
                result[index] = minHeap.top().first;
        }
        return result;
    }
};