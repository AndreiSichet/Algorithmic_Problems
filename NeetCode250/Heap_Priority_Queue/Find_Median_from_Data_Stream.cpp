/*
Find Median From Data Stream:

Use TWO heaps.

1. maxHeap:
       Stores the smaller half of the numbers.
       The largest number in this half is on top.

2. minHeap:
       Stores the larger half of the numbers.
       The smallest number in this half is on top.

Visual:

        smaller half          larger half
       MAX HEAP               MIN HEAP

       [1, 2, 3]  |  [7, 8, 10]
                ^     ^
               max   min

The median is around the boundary between the two heaps.

Rules:

    maxHeap.size() >= minHeap.size()

    maxHeap.size() - minHeap.size() <= 1

So the heaps have either:

    same size
    OR
    maxHeap has exactly one extra element.

Adding a number:

    If num <= maxHeap.top():
        put it in maxHeap
    else:
        put it in minHeap

Then rebalance:

    If maxHeap has more than one extra:
        move top of maxHeap -> minHeap

    If minHeap is larger:
        move top of minHeap -> maxHeap

Finding median:

    If same size:
        median = average of both tops

    Otherwise:
        median = maxHeap.top()

Why TWO heaps?

We need the middle values without sorting
the entire data stream every time.

Each insertion:
    O(log n)

Finding median:
    O(1)

Space:
    O(n)
*/
class MedianFinder {
private:
    // Smaller half.
    // Largest element of smaller half is on top.
    priority_queue<int> maxHeap;
    // Larger half.
    // Smallest element of larger half is on top.
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
    }
    void addNum(int num) {
        // Decide which half gets the number.
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        // Keep maxHeap at most one element larger.
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // minHeap should never be larger.
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double findMedian() {
        // Odd number of elements.
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        // Even number of elements.
        return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
    }
};