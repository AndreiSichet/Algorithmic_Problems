/*
Online Stock Span:

Use a monotonic decreasing stack.

Store:

    (price, span)

For each new price:

    span = 1

    While the stack is not empty
    and top.price <= current price:

        span += top.span
        pop

    Push (current price, span)

    Return span.

Main insight:

The stack stores previous prices
that are greater than the current one.

Each element also stores its span,
so when it is popped we can add all
those consecutive days at once,
instead of counting them again.

The stack remains in decreasing
order of prices.

Time Complexity:

next() -> O(1) amortized

Space Complexity: O(n)
*/
#include <iostream>
#include <stack>
using namespace std;
class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {

    }
    int next(int price) {
        int span = 1;
        while (!st.empty() &&st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({ price, span });
        return span;
    }
};
int main() {
    StockSpanner sp;
    cout << sp.next(100) << endl;
    cout << sp.next(80) << endl;
    cout << sp.next(60) << endl;
    cout << sp.next(70) << endl;
    cout << sp.next(60) << endl;
    cout << sp.next(75) << endl;
    cout << sp.next(85) << endl;
    return 0;
}