/*
Baseball Game:

Use a stack to store all valid scores.

Operations:

Number:
    push the score

"+":
    push the sum of the last two scores

"D":
    push double the last score

"C":
    remove the last score

Main insight:

Each operation only depends on the most
recent scores, making a stack the ideal
data structure.

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
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string op : operations) {
            if (op == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            }
            else if (op == "D") {
                st.push(2 * st.top());
            }
            else if (op == "C") {
                st.pop();
            }
            else {
                st.push(stoi(op));

            }
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
int main() {
    Solution sol;
    vector<string> ops1 = { "1","2","+","C","5","D" };
    vector<string> ops2 = { "5","D","+","C" };
    cout << "Example 1: "  << sol.calPoints(ops1)  << endl;
    cout << "Example 2: "   << sol.calPoints(ops2)    << endl;
    return 0;
}