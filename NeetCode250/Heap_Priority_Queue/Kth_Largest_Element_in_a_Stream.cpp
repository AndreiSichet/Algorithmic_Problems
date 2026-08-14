/*
Kth Largest Element in a Stream:

Use a min heap (priority_queue with greater<int>).

Keep only the k largest values in the heap.

Why a min heap?
    The smallest value among the k largest values
    is exactly the kth largest value.

For every new value:
    1. Add it to the heap.
    2. If heap size > k:
           remove the smallest value.
    3. heap.top() is the kth largest.

Example:
    k = 3
    values = [4,2,5,3]

After 4:
    [4]

After 2:
    [2,4]

After 5:
    [2,4,5]
    top = 2 -> 3rd largest

After 3:
    [3,4,5]
    remove 2
    top = 3 -> 3rd largest

Duplicates are handled automatically.

Main idea:
    Heap contains exactly the k largest values.
    The smallest of them is the kth largest.

Time:
    add() = O(log k)
    constructor = O(n log k)

Space:
    O(k)
*/

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }
    int add(int val) {
        minHeap.push(val);
        // Keep only k largest values.
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};