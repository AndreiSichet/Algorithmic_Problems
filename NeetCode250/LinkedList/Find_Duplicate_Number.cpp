/*
Find the Duplicate Number:
Treat the array like a linked list.
Each index points to: nums[index]
Since values are between 1 and n, every value is another valid index.
A duplicate value means multiple indices point to the same node.
This creates a cycle.
Use Floyd's Cycle Detection.
Phase 1:
Move
slow = nums[slow]
fast = nums[nums[fast]]
until they meet.
Phase 2:
Reset
slow = nums[0]
Move both one step at a time until they meet again.
The meeting point is the duplicate number.
Main insight:
The duplicate value is the
entry point of the cycle
formed by interpreting the
array as a linked list.
Time Complexity:
O(n)
Space Complexity:
O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        // Phase 1: Find intersection
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // Phase 2: Find entrance
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = { 1,2,3,2,2 };
    vector<int> nums2 = { 1,2,3,4,4 };
    vector<int> nums3 = { 3,1,3,4,2 };
    vector<int> nums4 = { 1,1 };
    cout << "Test 1: " << sol.findDuplicate(nums1) << endl;
    cout << "Test 2: " << sol.findDuplicate(nums2) << endl;
    cout << "Test 3: " << sol.findDuplicate(nums3) << endl;
    cout << "Test 4: " << sol.findDuplicate(nums4) << endl;
    return 0;
}