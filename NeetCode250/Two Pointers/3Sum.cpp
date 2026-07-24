/*
3Sum:

1. Sort the array.
2. Fix one element nums[i].
3. Use two pointers for the remaining elements:
       left = i + 1
       right = end

Calculate:
    nums[i] + nums[left] + nums[right]

If sum == 0:
    add the triplet
    move both pointers

If sum < 0:
    left++

If sum > 0:
    right--

Skip duplicate values to avoid duplicate triplets.

Time Complexity: O(n^2)
Space Complexity: O(1) extra space
(not counting the output)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while (left < right &&nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right &&nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return ans;
    }
};
void printResult(vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
int main() {
    Solution sol;
    vector<int> nums1 = { -1, 0, 1, 2, -1, -4 };
    vector<int> nums2 = { 0, 1, 1 };
    vector<int> nums3 = { 0, 0, 0 };
    vector<vector<int>> result1 = sol.threeSum(nums1);
    vector<vector<int>> result2 = sol.threeSum(nums2);
    vector<vector<int>> result3 = sol.threeSum(nums3);
    cout << "Example 1: ";
    printResult(result1);
    cout << "Example 2: ";
    printResult(result2);
    cout << "Example 3: ";
    printResult(result3);
    return 0;
}