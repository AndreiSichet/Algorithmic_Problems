/*
Trapping Rain Water:

Water above a bar depends on:

    min(maxLeft, maxRight) - height[i]

Use two pointers:
    left  -> beginning
    right -> end

Keep track of:
    maxLeft
    maxRight

If:
    height[left] <= height[right]

then the left side is the limiting side.

If height[left] is a new maximum:
    update maxLeft

Otherwise:
    add maxLeft - height[left] to the answer

Move:
    left++

Otherwise, process the right side:

If height[right] is a new maximum:
    update maxRight

Otherwise:
    add maxRight - height[right]

Move:
    right--

Main insight:

The shorter boundary determines how much water
can be trapped.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int water = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                }
                else {
                    water += maxLeft - height[left];
                }
                left++;
            }
            else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                }
                else {
                    water += maxRight - height[right];
                }
                right--;
            }
        }
        return water;
    }
};
int main() {
    Solution sol;
    vector<int> height = { 0, 2, 0, 3, 1,0, 1, 3, 2, 1 };
    cout << sol.trap(height) << endl;
    return 0;
}