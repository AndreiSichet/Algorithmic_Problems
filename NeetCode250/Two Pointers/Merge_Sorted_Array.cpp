/*
Merge Sorted Array:

Use 3 pointers:
    i = m - 1       last valid element in nums1
    j = n - 1       last element in nums2
    k = m + n - 1   last position in nums1

Compare nums1[i] and nums2[j].
Place the larger value at nums1[k].

Move the corresponding pointer backwards.

We merge from right to left because nums1 has empty
spaces at the end and we must not overwrite its valid values.

After the main loop, copy any remaining elements from nums2.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        // If nums2 still has elements,
        // copy them into nums1.
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
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
    vector<int> nums1 = { 10, 20, 20, 40, 0, 0 };
    vector<int> nums2 = { 1, 2 };
    sol.merge(nums1, 4, nums2, 2);
    cout << "Example 1: ";
    printVector(nums1);
    vector<int> nums3 = { 0, 0 };
    vector<int> nums4 = { 1, 2 };
    sol.merge(nums3, 0, nums4, 2);
    cout << "Example 2: ";
    printVector(nums3);
    return 0;
}