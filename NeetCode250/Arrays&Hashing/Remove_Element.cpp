/*
Notes:
Use the two-pointer technique.
The fast pointer (i) scans every element.
The slow pointer (k) marks the position where the next valid element should be placed.
If nums[i] != val:
    nums[k] = nums[i]
    k++
At the end, k represents the number of elements that are not equal to val.
We do not need to actually remove elements from the vector.
We simply overwrite the beginning of the vector with the elements we want to keep.
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
            else continue;
        }
        return k;
    }
};
int main() {
    vector<int> nums1 = { 3,2,2,3 };
    int val1 = 3;
    vector<int>nums2 = { 0,1,2,2,3,0,4,2 };
    int val2 = 2;
    Solution sol;
    cout << "Output1: " << sol.removeElement(nums1, val1) << endl;
    cout << "Output2: " << sol.removeElement(nums2, val2) << endl;
}