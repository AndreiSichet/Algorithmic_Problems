/*
Binary Search:

Works only on a sorted array.

Maintain two pointers:

left
right

While left <= right:

	Compute the middle index.

	If nums[mid] == target:
		return mid.

	If nums[mid] < target:
		Search the right half.

	Otherwise:
		Search the left half.

If the loop ends,
the target is not present.

Main insight:

At each step, compare the
middle element with the target.

Because the array is sorted,
one entire half can be discarded.

This cuts the search space
in half every iteration.

Important details:

- Use while(left <= right)
  so the last remaining element
  is checked.

- Compute mid as:

  left + (right - left) / 2

  to avoid integer overflow.

Time Complexity:

O(log n)

Space Complexity:

O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return -1;
	}
};
int main() {
	Solution sol;
	vector<int> nums = { -1,0,2,4,6,8 };
	cout << sol.search(nums, 4) << endl;
	cout << sol.search(nums, 3) << endl;
	return 0;
}