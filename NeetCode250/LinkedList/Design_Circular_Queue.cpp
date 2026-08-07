/*
Design Circular Queue:
Implement a queue using a fixed-size array.
Instead of shifting elements, wrap indices using modulo.
Move rear: rear = (rear + 1) % capacity
Move front: front = (front + 1) % capacity
Store:
front
rear
count
capacity
Use count to distinguish between:
empty
(count == 0)
and
full
(count == capacity)
Main insight:
A circular queue reuses
empty positions at the
front by wrapping around
to the beginning of the
array.
This avoids shifting
elements and keeps every
operation O(1).
Time Complexity:
All operations: O(1)
Space Complexity: O(k)
*/
class MyCircularQueue {
    vector<int> q;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        q.resize(k);
        capacity = k;
        front = 0;
        rear = -1;
        count = 0;
    }
    bool enQueue(int value) {
        if (isFull())
            return false;
        rear = (rear + 1) % capacity;
        q[rear] = value;
        count++;
        return true;
    }
    bool deQueue() {
        if (isEmpty())
            return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }
    int Front() {
        if (isEmpty())
            return -1;
        return q[front];
    }
    int Rear() {
        if (isEmpty())
            return -1;
        return q[rear];
    }
    bool isEmpty() {
        return count == 0;
    }
    bool isFull() {
        return count == capacity;
    }
};