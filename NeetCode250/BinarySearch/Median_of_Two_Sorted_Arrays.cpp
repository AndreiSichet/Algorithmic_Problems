/*
Median of Two Sorted Arrays:

Binary search on the smaller array.

Goal:

Partition both arrays so that

- Left half contains exactly
  half of the total elements.

- Every element on the left
  is <= every element on
  the right.

For a partition:

cut1 = partition in nums1

cut2 = totalLeft - cut1

Compute:

left1
right1
left2
right2

using INT_MIN and INT_MAX
when the partition is at
the ends of an array.

Correct partition if:

left1 <= right2

AND

left2 <= right1

If left1 > right2:

Move cut1 left.

If left2 > right1:

Move cut1 right.

Answer:

Odd number of elements:

max(left1,left2)

Even number:

(max(left1,left2)
+
min(right1,right2))
/2.0

Main insight:

Instead of merging arrays,
find the partition where
everything on the left
belongs before everything
on the right.

Always binary search the
smaller array.

Time Complexity:

O(log(min(m,n)))

Space Complexity:

O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        int totalLeft = (m + n + 1) / 2;
        while (left <= right) {
            int cut1 = left + (right - left) / 2;
            int cut2 = totalLeft - cut1;
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                return max(left1, left2);
            }
            else if (left1 > right2) {
                right = cut1 - 1;
            }
            else {
                left = cut1 + 1;
            }
        }
        return 0;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,3 };
    vector<int> b = { 2,4 };
    cout << sol.findMedianSortedArrays(a, b);
    return 0;
}