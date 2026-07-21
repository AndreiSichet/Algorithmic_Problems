/*
Product of Array Except Self:

For every index i:

    answer[i] =
        product of elements on the LEFT
        *
        product of elements on the RIGHT

1. Prefix pass:
   Store the product of all elements before i.

2. Suffix pass:
   Go from right to left and multiply by the
   product of all elements after i.

Example:
    nums   = [1, 2, 4, 6]
    output = [48, 24, 12, 8]

No division, so it also works with 0.

Time Complexity:
    O(n)

Space Complexity:
    O(1) extra space

Main idea:
Prefix product * Suffix product.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, 1);
		int prefix = 1;
		for (int i = 0; i < n; i++) {
			ans[i] = prefix;
			prefix *= nums[i];
		}
		int suffix = 1;
		for (int i = n-1; i >= 0; i--) {
			ans[i] *= suffix;
			suffix *= nums[i];
		}
		return ans;
	}
};
int main() {
    Solution solution;
    vector<int> nums1 = { 1, 2, 4, 6 };
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Output 1: ";
    for (int x : result1) {
        cout << x << " ";
    }
    cout << endl;
    vector<int> nums2 = { -1, 0, 1, 2, 3 };
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Output 2: ";
    for (int x : result2) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}