/*
Search Insert Position:

Use standard binary search.

Maintain:

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

If the target is not found,
return left.

Main insight:

When binary search ends,
left points to the first position
where the target can be inserted
while keeping the array sorted.

Important details:

- Return left, not right.
- left is the insertion position.
- Use:

  mid = left + (right - left) / 2

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
    int searchInsert(vector<int>& nums, int target) {
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
        return left;
    }

};
int main() {
    Solution sol;
    vector<int> nums = { -1,0,2,4,6,8 };
    cout << sol.searchInsert(nums, 5) << endl;
    cout << sol.searchInsert(nums, 10) << endl;
    return 0;
}