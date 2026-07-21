/*
Subarray Sum Equals K:

Use Prefix Sum + Hash Map.

currentSum = sum of elements up to the current index.
We want:

currentSum - previousSum = k

Therefore:

previousSum = currentSum - k

For every currentSum, check if currentSum - k
has appeared before.

The map stores:

prefixSum -> frequency

Important:

freq[0] = 1;

This represents the empty prefix before the array starts
and allows us to count subarrays that start at index 0.

Algorithm:
1. Add the current number to currentSum.
2. Check if currentSum - k exists in the map.
3. Add its frequency to the answer.
4. Store currentSum in the map.

Time Complexity: O(n)
Space Complexity: O(n)

Works with negative numbers.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int currentSum = 0;
        int ans = 0;
        freq[0] = 1;
        for (int num : nums) {
            currentSum += num;
            int needed = currentSum - k;
            if (freq.count(needed)) {
                ans += freq[needed];
            }
            freq[currentSum]++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = { 2, -1, 1, 2 };
    int k1 = 2;
    vector<int> nums2 = { 4, 4, 4, 4, 4, 4 };
    int k2 = 4;
    cout << "Example 1: "
        << sol.subarraySum(nums1, k1)
        << endl;
    cout << "Example 2: "
        << sol.subarraySum(nums2, k2)
        << endl;
    return 0;
}