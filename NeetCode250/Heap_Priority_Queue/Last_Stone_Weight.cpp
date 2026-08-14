/*
Last Stone Weight:

Use a max heap because we always need
the two heaviest stones.

For every step:
    1. Take the largest stone.
    2. Take the second largest stone.
    3. If they are equal:
           both are destroyed.
    4. Otherwise:
           push the difference back into the heap.

Continue until at most one stone remains.

Example:
    [2,7,4,1,8,1]

Max heap gives:
    8, 7
    8 - 7 = 1
    push 1

Now repeat with the two heaviest.

Why max heap?
    heap.top() always gives the heaviest stone.

Time: O(N log N)
    At most N stones are processed.

Space: O(N)
    Heap stores the stones.
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        // Add all stones to max heap.
        for (int stone : stones) {
            maxHeap.push(stone);
        }
        while (maxHeap.size() > 1) {
            // Two heaviest stones.
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            // If different, push remaining weight.
            if (x != y) {
                maxHeap.push(x - y);
            }
        }
        // No stones left.
        if (maxHeap.empty()) {
            return 0;
        }
        // One stone remains.
        return maxHeap.top();
    }
};