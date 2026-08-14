/*
K Closest Points to Origin:

Use a max heap of size k.

Distance from (x,y) to origin:
    sqrt(x^2 + y^2)

We do not need sqrt().
Compare squared distance instead:

    distance = x^2 + y^2

Why max heap?
    We want to keep the k closest points.

    The max heap stores the k closest points,
    with the farthest of them at the top.

For each point:
    1. Calculate squared distance.
    2. Push {distance, point} into max heap.
    3. If size > k:
           remove the farthest point.

At the end:
    heap contains exactly the k closest points.

Example:
    k = 2

    points:
        [1,1] -> distance = 2
        [2,2] -> distance = 8
        [0,1] -> distance = 1

    Keep:
        [1,1], [0,1]

    [2,2] gets removed because it is farthest.

Main idea:
    Max heap of size k.
    Top = farthest among our current k closest.

Time: O(N log K)
Space: O(K)
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // {distance, point}
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            int distance = x * x + y * y;
            maxHeap.push({distance,{x, y}});
            // Keep only k closest points.
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            auto point = maxHeap.top().second;
            maxHeap.pop();
            result.push_back({point.first,point.second});
        }
        return result;
    }
};