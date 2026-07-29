/*
Minimum Size Subarray Sum:

Use a sliding window.

Keep:
    left
    right
    currentSum

Expand the window by moving right:
    currentSum += nums[right]

When:
    currentSum >= target

the window is valid.

Try to shrink it from the left
to find the minimum length.

While the window is still valid:
    update the minimum length
    remove nums[left]
    left++

Main insight:

Since all numbers are positive,
expanding the window increases the sum,
and shrinking the window decreases the sum.

This allows us to find the answer
in one pass.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (minLength == INT_MAX)
            return 0;
        return minLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = { 2,1,5,1,5,3 };
    cout << sol.minSubArrayLen(10, nums1) << endl;
    vector<int> nums2 = { 1,2,1 };
    cout << sol.minSubArrayLen(5, nums2) << endl;
    return 0;
}