/*
Notes:
Used a hash map as a frequency counter to see whether there are elements with a frequency bigger than 1 in the array.
Time Complexity: O(n), keep in mind hashmap insertion/access is O(1)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& pair : freq) {
            if (pair.second > 1) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    vector<int> nums1 = { 1, 2, 3, 3 };
    vector<int> nums2 = { 1, 2, 3, 4 };
    Solution sol;
    cout << "Output1: " << sol.hasDuplicate(nums1) << endl;
    cout << "Output2: " << sol.hasDuplicate(nums2) << endl;
}