/*
Contains Duplicate II:

Use a HashSet as a sliding window.

The window stores only the last k elements.

For each number:

1. If it is already in the set,
   return true.

2. Otherwise, insert it.

3. If the window becomes larger than k,
   remove the element that is k positions behind:
       nums[i - k]

Main insight:

The set always contains only the elements
whose indices are within k positions of
the current index.

Time Complexity: O(n)
Space Complexity: O(min(n, k))
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i])) {
                return true;
            }
            window.insert(nums[i]);
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = { 1,2,3,1 };
    int k1 = 3;
    cout << boolalpha << sol.containsNearbyDuplicate(nums1, k1) << endl;
    vector<int> nums2 = { 2,1,2 };
    int k2 = 1;
    cout << boolalpha << sol.containsNearbyDuplicate(nums2, k2) << endl;
    return 0;
}