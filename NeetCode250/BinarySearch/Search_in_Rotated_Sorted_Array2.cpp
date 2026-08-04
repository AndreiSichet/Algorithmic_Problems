/*
Search in Rotated Sorted Array II:

Same idea as Search in
Rotated Sorted Array,
but duplicates are allowed.

At every step:

    Compute mid.

If nums[mid] == target:

    Return true.

Special case:

If

nums[left] == nums[mid]
&&
nums[mid] == nums[right]

We cannot determine
which half is sorted.

Discard both ends:

left++
right--

Otherwise:

If nums[left] <= nums[mid]:

    Left half is sorted.

    If target lies inside it:

        Search left.

    Otherwise:

        Search right.

Else:

    Right half is sorted.

    If target lies inside it:

        Search right.

    Otherwise:

        Search left.

Main insight:

Duplicates can hide
the rotation point.

When both ends equal
the middle, shrink the
search space until one
sorted half becomes visible.

Important details:

- Check nums[mid] first.
- Handle duplicates before
  checking the sorted half.
- Worst-case complexity
  becomes O(n).

Time Complexity:

Average: O(log n)

Worst: O(n)

Space Complexity:

O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            // Cannot determine the sorted half
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Left half is sorted
            else if (nums[left] <= nums[mid]) {
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
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 3,4,4,5,6,1,2,2 };
    cout << sol.search(nums, 1);
    return 0;
}