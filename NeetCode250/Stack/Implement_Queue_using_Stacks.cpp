/*
Implement Queue Using Stacks:

Use two stacks:

    inStack
    outStack

push(x):

    Push x into inStack.

pop():

    If outStack is empty,
    move all elements from
    inStack to outStack.

    Pop from outStack.

peek():

    If outStack is empty,
    move all elements from
    inStack to outStack.

    Return outStack.top().

empty():

    Both stacks must be empty.

Main insight:

Moving elements from one stack to
the other reverses their order.

The oldest inserted element becomes
the top of outStack, giving FIFO
behavior.

Each element is moved at most once,
so pop() and peek() are O(1)
amortized.

Time Complexity:

push  -> O(1)
pop   -> O(1) amortized
peek  -> O(1) amortized
empty -> O(1)

Space Complexity: O(n)
*/
#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
    stack<int> inStack;
    stack<int> outStack;
public:
    MyQueue() {
    }
    void push(int x) {
        inStack.push(x);
    }
    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << boolalpha<< q.empty() << endl;
    return 0;
}