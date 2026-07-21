/*
First Missing Positive:

Use the array itself to place numbers in their correct positions.

For an array of size n:
    number 1 -> index 0
    number 2 -> index 1
    number x -> index x - 1

Ignore numbers that are:
    <= 0
    > n

After placing the numbers, scan the array.

If:
    nums[i] != i + 1

then i + 1 is the first missing positive.

If all positions are correct:
    return n + 1.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Put every number x in position x - 1
        for (int i = 0; i < n; i++) {
            while ( nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i] ) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
       // Find the first number in the wrong position
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = { -2, -1, 0 };
    vector<int> nums2 = { 1, 2, 4 };
    vector<int> nums3 = { 1, 2, 4, 5, 6, 3, 1 };
    cout << "Example 1: "
        << sol.firstMissingPositive(nums1)
        << endl;
    cout << "Example 2: "
        << sol.firstMissingPositive(nums2)
        << endl;
    cout << "Example 3: "
        << sol.firstMissingPositive(nums3)
        << endl;
    return 0;
}