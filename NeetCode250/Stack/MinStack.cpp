/*
Min Stack:

Use two stacks:

    stack    -> stores all values
    minStack -> stores the minimum values

push(val):

    Push val into stack.

    If minStack is empty or
    val <= minStack.top(),
    also push val into minStack.

pop():

    If the popped value equals
    the current minimum,
    pop from minStack too.

top():

    Return stack.top().

getMin():

    Return minStack.top().

Main insight:

minStack keeps track of the minimum
value at every moment.

The top of minStack is always the
minimum element in O(1).

Use <= when pushing into minStack
to correctly handle duplicate
minimum values.

Time Complexity:

push    -> O(1)
pop     -> O(1)
top     -> O(1)
getMin  -> O(1)

Space Complexity: O(n)
*/
#include <iostream>
#include <stack>
using namespace std;
class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {

    }
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return minSt.top();
    }
};
int main() {
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}