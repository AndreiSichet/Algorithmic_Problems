/*
Find Minimum in Rotated Sorted Array:

Use modified binary search.

The array consists of two
sorted parts separated by
the rotation point.

The minimum is the first
element of the second
sorted part.

Maintain:

left
right

While left < right:

    Compute the middle.

    Compare nums[mid]
    with nums[right].

    If nums[mid] > nums[right]:

        The minimum is in
        the right half.

        left = mid + 1

    Otherwise:

        The minimum is at
        mid or in the left half.

        right = mid

When left == right,
that index is the minimum.

Main insight:

Comparing with the last
element tells which sorted
portion mid belongs to.

Important details:

- Use left < right.
- Do NOT do right = mid - 1.
- Keep mid because it may
  already be the minimum.

Time Complexity:

O(log n)

Space Complexity:

O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 3,4,5,6,1,2 };
    cout << sol.findMin(nums);
    return 0;
}