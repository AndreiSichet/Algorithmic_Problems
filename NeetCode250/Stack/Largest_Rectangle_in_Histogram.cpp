/*
Largest Rectangle in Histogram:

Use a monotonic increasing stack.

Each stack entry stores:

(height, leftmost_index)

For every bar:

If the current height is greater
than or equal to the top of the stack,
push it.

If the current height is smaller:

    Pop taller bars.

    For each popped bar:

        width = current_index - start_index

        area = height × width

        Update the maximum area.

    Keep the popped bar's start index,
    because the current shorter bar can
    extend that far to the left.

After scanning the array,
pop all remaining bars.

Their right boundary is the end
of the histogram.

Main insight:

Each bar is treated as the
shortest bar of a rectangle.

The stack helps find the first
smaller bar on the left and right,
allowing us to compute the
maximum width for each height.

Time Complexity:

O(n)

Space Complexity:

O(n)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!st.empty() && st.top().first > heights[i]) {
                int height = st.top().first;
                int index = st.top().second;
                st.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            st.push({ heights[i], start });
        }
        while (!st.empty()) {
            int height = st.top().first;
            int index = st.top().second;
            st.pop();
            maxArea = max(maxArea, height * ((int)heights.size() - index));
        }
        return maxArea;
    }
};
int main() {
    Solution sol;
    vector<int> h1 = { 7,1,7,2,2,4 };
    vector<int> h2 = { 1,3,7 };
    cout << sol.largestRectangleArea(h1) << endl;
    cout << sol.largestRectangleArea(h2) << endl;
    return 0;
}