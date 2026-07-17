/*
Notes:
Use a hashmap to store the indices of each number in the array.
While doing that search if the complement to target is already in the map and if so return the pair of indices.
If the loop ends and no pair were returned, return {};
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return{ mp[complement],i };
            }
            mp[nums[i]] = i;
        }
        return{};
    }
};
int main() {
    vector<int>nums1 = { 3,4,5,6 };
    int target1 = 7;
    vector<int>nums2 = { 4,5,6 };
    int target2 = 10;
    vector<int>nums3 = { 5,5 };
    int target3 = 10;
    Solution sol;
    cout << "Output1: ";
    for (int i : sol.twoSum(nums1, target1) {
        cout<<i<<" ";
    }
    cout << "Output2: ";
    for (int i : sol.twoSum(nums2, target2) {
         cout << i << " ";
    }
    cout << "Output3: ";
    for (int i : sol.twoSum(nums3, target3) {
         cout << i << " ";
    }
}
