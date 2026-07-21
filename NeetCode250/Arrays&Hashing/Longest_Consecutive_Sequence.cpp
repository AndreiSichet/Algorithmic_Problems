/*
Longest Consecutive Sequence:

Use an unordered_set for O(1) average lookup.

For every number, start a sequence only if:

    num - 1 does not exist

Then count:

    num, num + 1, num + 2, ...

Example:
    [2, 3, 4, 5]

    2 - 1 does not exist
    -> start counting from 2

Duplicates are automatically removed
by the unordered_set.

Time: O(n)
Space: O(n)

Main idea:
Only start counting from the beginning
of each sequence.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : numSet) {
            // Start counting only if num is the beginning of a sequence.
            if (!numSet.count(num - 1)) {
                int length = 1;
                int current = num;
                while (numSet.count(current + 1)) {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = { 2, 20, 4, 10, 3, 4, 5 };
    cout << solution.longestConsecutive(nums1) << endl;
    vector<int> nums2 = { 0, 3, 2, 5, 4, 6, 1, 1 };
    cout << solution.longestConsecutive(nums2) << endl;
    return 0;
}