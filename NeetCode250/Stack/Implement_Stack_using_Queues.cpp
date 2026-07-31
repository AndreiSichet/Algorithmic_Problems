/*
Implement Stack Using Queues:

Use one queue.

For push(x):

1. Push x into the queue.

2. Rotate the previous elements
   to the back.

Example:

Queue before push:

1 2

Push 3:

1 2 3

Rotate:

2 3 1

Rotate:

3 1 2

Now the newest element is at
the front of the queue.

pop():
    remove the front.

top():
    return the front.

Main insight:

By rotating the queue after every
push, the front of the queue
always behaves like the top
of a stack.

Time Complexity:

push  -> O(n)
pop   -> O(1)
top   -> O(1)
empty -> O(1)

Space Complexity: O(n)
*/
#include <iostream>
#include <queue>
using namespace std;
class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    int top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};
int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << boolalpha<< st.empty()<< endl;
    return 0;
}