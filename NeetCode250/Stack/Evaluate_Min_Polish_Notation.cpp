/*
Evaluate Reverse Polish Notation:

Use a stack.

For each token:

If it is a number:
    push it onto the stack.

If it is an operator:

    Pop the last two numbers.

    Be careful with the order:

        b = top
        pop

        a = top
        pop

    Compute:

        a op b

    Push the result back.

At the end,
the stack contains one value:
the answer.

Main insight:

Numbers are stored until an
operator appears.

Each operator combines the two
most recent operands into a
single value.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" ||  token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            }
            else {
                st.push(stoi(token));

            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    vector<string> tokens ={ "1","2","+","3","*","4","-" };
    cout << sol.evalRPN(tokens);
    return 0;
}