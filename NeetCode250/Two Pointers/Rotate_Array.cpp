/*
Rotate Array:

To rotate the array to the right by k positions:

1. Reverse the entire array.
2. Reverse the first k elements.
3. Reverse the remaining elements.

Example:
    [1,2,3,4,5,6,7,8]
    k = 4

Reverse all:
    [8,7,6,5,4,3,2,1]

Reverse first k:
    [5,6,7,8,4,3,2,1]

Reverse the rest:
    [5,6,7,8,1,2,3,4]

Use:
    k = k % n

because rotating n positions returns the array
to its original state.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
void printVector(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
int main() {
    Solution sol;
    vector<int> nums1 = { 1,2,3,4,5,6,7,8 };
    int k1 = 4;
    sol.rotate(nums1, k1);
    cout << "Example 1: ";
    printVector(nums1);
    vector<int> nums2 = { 1000,2,4,-3 };
    int k2 = 2;
    sol.rotate(nums2, k2);
    cout << "Example 2: ";
    printVector(nums2);
    return 0;
}