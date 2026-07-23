/*
Remove Duplicates From Sorted Array:

The array is sorted, so duplicates are next to each other.

Use two pointers:
    i = position of the last unique element
    j = scans the array

If:
    nums[j] != nums[i]

then nums[j] is a new unique element.

Move i forward and copy:
    nums[i] = nums[j]

The number of unique elements is:
    k = i + 1

Only the first k elements matter.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
void printVector(vector<int>& nums, int k) {
    cout << "[";
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
int main() {
    Solution sol;
    vector<int> nums1 = { 1, 1, 2, 3, 4 };
    int k1 = sol.removeDuplicates(nums1);
    cout << "Example 1: ";
    printVector(nums1, k1);
    cout << "k = " << k1 << endl;
    vector<int> nums2 = { 2, 10, 10, 30, 30, 30 };
    int k2 = sol.removeDuplicates(nums2);
    cout << "Example 2: ";
    printVector(nums2, k2);
    cout << "k = " << k2 << endl;
    return 0;
}