/*
Kth Largest Element in an Array:

Use a min heap of size k.

Why?
    We only need the k largest values.

    The min heap keeps those k values,
    with the smallest of them at the top.

    The smallest among the k largest
    is exactly the kth largest element.

For every number:
    1. Push it into the min heap.
    2. If size > k:
           remove the smallest value.

At the end:
    heap.top() = kth largest.

Example:
    nums = [3,2,1,5,6,4]
    k = 2

    Keep the 2 largest values.

    Final heap:
        [5,6]

    heap.top() = 5

    Therefore answer = 5.

Important pattern:

    kth largest:
        min heap of size k

    kth smallest:
        max heap of size k

Time: O(N log K)
Space: O(K)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            // Keep only the k largest elements.
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};