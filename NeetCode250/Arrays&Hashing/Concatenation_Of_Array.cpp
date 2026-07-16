
/*
Notes:
Used the insert function from the std:vector.
Usage of insert() function:
v.insert(pos, val);   // Insert single element 
v.insert(pos, n, val);   // Insert multiple copies of an element
v.insert(pos, { val1, val2, ... })   // Insert list of elements
v.insert(pos, first, last);   // Insert range of elements 
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> getConcatenation(vector<int>& nums) {
		vector<int>ans = nums;
		ans.insert(ans.end(), nums.begin(), nums.end());
		return ans;
	}
};
int main() {
	vector<int> nums1 = { 1,4,1,2 };
	vector<int>nums2 = { 22,21,20,1 };
	Solution sol;
	cout << "Output1: ";
	for (int x : sol.getConcatenation(nums1)) {
		cout << x << " ";
	}
	cout << "\nOutput2: ";
	for (int x : sol.getConcatenation(nums2)) {
		cout << x << " ";
	}
}