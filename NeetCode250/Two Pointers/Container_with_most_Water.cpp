/*
Container With Most Water:

Use two pointers:
    left  -> beginning
    right -> end

Area:
    (right - left) *
    min(height[left], height[right])

The shorter bar limits the amount of water.

After calculating the area:
    move the pointer pointing to the shorter bar.

Why?

Moving the taller bar only decreases the width,
while the shorter bar still limits the height.

Moving the shorter bar gives us a chance to find
a taller bar and increase the area.

Keep track of the maximum area found.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while (left < right) {
            int width = right - left;
            int currentHeight =min(height[left], height[right]);
            int area = width * currentHeight;
            maxWater = max(maxWater, area);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxWater;
    }
};
int main() {
    Solution sol;
    vector<int> height1 = { 1, 7, 2, 5, 4, 7, 3, 6 };
    vector<int> height2 = { 2, 2, 2 };
    cout << "Example 1: "<< sol.maxArea(height1)<< endl;
    cout << "Example 2: "<< sol.maxArea(height2)<< endl;
    return 0;
}