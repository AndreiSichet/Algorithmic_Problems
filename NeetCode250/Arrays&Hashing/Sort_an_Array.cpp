/*
Merge Sort:

Divide and Conquer algorithm.

1. Divide:
   Split the array into two halves.

2. Recursively sort:
   Sort each half using Merge Sort.

3. Merge:
   Merge the two sorted halves into one sorted array.

Example:
[5, 2, 3, 1]

Divide:
[5, 2] [3, 1]

Divide:
[5] [2] [3] [1]

Merge:
[2, 5] [1, 3]

Final merge:
[1, 2, 3, 5]

Time Complexity: O(n log n)
Space Complexity: O(n)

The array is divided into log(n) levels,
and at each level we process all n elements.

Merge Sort is a stable sorting algorithm.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
int main() {
    vector<int> nums1 = { 10,9,1,1,1,2,3,1 };
    vector<int> nums2 = { 5,10,2,1,3 };
    Solution sol;
    cout << "Output1: ";
    for (int i : sol.sortArray(nums1)) {
        cout << i << " ";
    }
    cout << "\nOutput2: ";
    for (int i : sol.sortArray(nums2)) {
        cout << i << " ";
    }
}