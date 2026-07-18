/*
Dutch National Flag Algorithm:

Use three pointers:
left:
    Position where the next 0 should go.

current:
    Element currently being inspected.

right:
    Position where the next 2 should go.

The array is divided into four regions:

[0 ... left - 1]       -> sorted 0s
[left ... current - 1] -> sorted 1s
[current ... right]    -> unknown elements
[right + 1 ... end]    -> sorted 2s

Rules:

If nums[current] == 0:
    Swap it with nums[left].
    Move left and current forward.

If nums[current] == 1:
    It is already in the correct middle section.
    Move current forward.

If nums[current] == 2:
    Swap it with nums[right].
    Move right backward.

Important:
When swapping a 2 with nums[right], do NOT increment current.
The element swapped from the right is still unknown,
so we need to inspect it.

Time Complexity: O(n)
Space Complexity: O(1)

The algorithm makes only one pass through the array
and sorts the array in-place.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int current = 0;
        int right = nums.size() - 1;
        while (current <= right) {
            if (nums[current] == 0) {
                swap(nums[left], nums[current]);
                left++;
                current++;
            }
            else if (nums[current] == 1) {
                current++;
            }
            else { 
                swap(nums[current], nums[right]);
                right--;
            }
        }
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = { 1, 0, 1, 2 };
    vector<int> nums2 = { 2, 1, 0 };
    sol.sortColors(nums1);
    sol.sortColors(nums2);
    cout << "Output 1: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Output 2: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}