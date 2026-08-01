/*
Daily Temperatures:

Use a monotonic decreasing stack.

The stack stores indices,
not temperatures.

For each day:

While the current temperature
is warmer than the temperature
at the top index of the stack:

    Pop the index.

    The answer is:

        currentIndex - poppedIndex

Push the current index.

Main insight:

The stack stores days that are
still waiting for a warmer day.

When a warmer temperature appears,
it resolves one or more previous days.

Store indices so you can calculate
the number of days waited.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                answer[index] = i - index;
            }
            st.push(i);
        }
        return answer;
    }
};
void print(vector<int> nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i + 1 != nums.size())
            cout << ",";
    }
    cout << "]" << endl;
}
int main() {
    Solution sol;
    vector<int> t1 = { 30,38,30,36,35,40,28 };
    vector<int> t2 = { 22,21,20 };
    print(sol.dailyTemperatures(t1));
    print(sol.dailyTemperatures(t2));
    return 0;
}