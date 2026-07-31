/*
Valid Parentheses:

Use a stack.

For each character:

Opening bracket:
    push it onto the stack.

Closing bracket:
    the stack must not be empty,
    and the top must contain
    the matching opening bracket.

If it doesn't match:
    return false.

Otherwise:
    pop the opening bracket.

At the end:

If the stack is empty,
all brackets were matched correctly.

Main insight:

The last opening bracket must be
the first one to be closed (LIFO),
which makes a stack the perfect
data structure.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.empty())
                    return false;
                if (c == ')' && st.top() != '(')
                    return false;
                if (c == ']' && st.top() != '[')
                    return false;
                if (c == '}' && st.top() != '{')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.isValid("[]") << endl;
    cout << sol.isValid("([{}])") << endl;
    cout << sol.isValid("[(])") << endl;
    return 0;
}