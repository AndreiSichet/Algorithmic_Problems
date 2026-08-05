/*
Split Array Largest Sum:

Binary Search on Answer.

We are NOT searching
for where to split.

We binary search the
largest allowed subarray sum.

Search range:

left

    Maximum element.

right

    Sum of the array.

For each candidate limit:

Greedily build subarrays.

Keep adding numbers until
adding another number would
exceed the limit.

Then start a new subarray.

Count how many subarrays
are needed.

If count <= k:

    Limit is possible.

    Try a smaller limit.

Else:

    Need a larger limit.

Main insight:

The greedy approach produces
the minimum number of
subarrays for a given limit.

The answer is monotonic:

Small limit

    Impossible.

Large limit

    Possible.

This monotonic property
allows binary search.

Time Complexity:

O(n log(sum))

Space Complexity:

O(1)
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int limit) {
        int count = 1;
        int sum = 0;
        for (int num : nums) {
            if (sum + num <= limit) {
                sum += num;
            }
            else {
                count++;
                sum = num;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = 0;
        for (int num : nums) {
            right += num;
        }
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = { 2,4,10,1,5 };
    cout << sol.splitArray(nums, 2);
    return 0;
}