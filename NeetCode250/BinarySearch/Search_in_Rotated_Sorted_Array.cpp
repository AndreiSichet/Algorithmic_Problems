/*
Search in Rotated Sorted Array:

Use modified binary search.

At every step:

    One half of the array
    is always sorted.

Compute:

    mid

If nums[mid] == target:

    Return mid.

Determine which half
is sorted.

If nums[left] <= nums[mid]:

    Left half is sorted.

    If target lies between

        nums[left]
        and
        nums[mid]

    Search left.

    Otherwise search right.

Else:

    Right half is sorted.

    If target lies between

        nums[mid]
        and
        nums[right]

    Search right.

    Otherwise search left.

If the search ends,
the target does not exist.

Main insight:

A rotated sorted array always
contains one completely sorted
half.

Identify that half first,
then decide if the target
belongs there.

Important details:

- Use left <= right.
- Check nums[mid] first.
- Compare nums[left]
  with nums[mid] to detect
  the sorted half.

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
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 3,4,5,6,1,2 };
    cout << sol.search(nums, 1);
    return 0;
}