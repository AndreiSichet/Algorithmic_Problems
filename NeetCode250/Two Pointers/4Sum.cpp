/*
4Sum:

4Sum extends the 3Sum approach.

First, sort the array.

Then use:
    i      -> first number
    j      -> second number
    left   -> third number
    right  -> fourth number

The first loop is:

    for (int i = 0; i < n - 3; i++)

Why n - 3?

We need 3 more elements after nums[i]:
    nums[i]
    nums[j]
    nums[left]
    nums[right]

So i cannot be one of the last 3 positions.

For example, if i is at index n - 3,
there are still exactly 3 positions after it.

If i > n - 3, there are not enough elements left
to form a quadruplet.

The second loop goes until:

    j < n - 2

because after choosing nums[i] and nums[j],
we still need 2 more elements:
    left
    right

The array is sorted, so the two-pointer technique works.

If the sum is too small:
    left++

This increases the sum.

If the sum is too large:
    right--

This decreases the sum.

If the sum equals target:
    save the quadruplet
    move both pointers

Skip duplicate values to avoid duplicate quadruplets.

Use long long for the sum because adding 4 integers
could cause integer overflow.

Main insight:

Instead of checking every combination of 4 elements
with 4 nested loops, fix the first 2 elements and solve
the remaining 2Sum problem with two pointers.

Brute force:
    O(n^4)

Optimized:
    O(n^3)

Time Complexity: O(n^3)
Space Complexity: O(1) extra space
(not counting the output)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    long long sum =(long long)nums[i]+ nums[j]+ nums[left]+ nums[right];
                    if (sum == target) {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while (left < right &&nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right &&nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

void printResult(vector<vector<int>>& result) {
    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << "[";

        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];

            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }

        cout << "]";

        if (i < result.size() - 1) {
            cout << ",";
        }
    }

    cout << "]" << endl;
}
int main() {
    Solution sol;
    vector<int> nums1 = { 3, 2, 3, -3, 1, 0 };
    int target1 = 3;
    vector<vector<int>> result1 =sol.fourSum(nums1, target1);
    cout << "Example 1: ";
    printResult(result1);
    vector<int> nums2 = { 1, -1, 1, -1, 1, -1 };
    int target2 = 2;
    vector<vector<int>> result2 =sol.fourSum(nums2, target2);
    cout << "Example 2: ";
    printResult(result2);
    return 0;
}