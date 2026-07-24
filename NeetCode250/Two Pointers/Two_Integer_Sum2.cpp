/*
Two Sum II:

The array is sorted, so use two pointers:

left  -> beginning
right -> end

Calculate:
	sum = numbers[left] + numbers[right]

If:
	sum == target
		return the indices

If:
	sum < target
		left++

If:
	sum > target
		right--

The problem uses 1-based indexing,
so return:
	left + 1
	right + 1

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int>twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right) {
			int sum = numbers[left] + numbers[right];
			if (sum == target) {
				return { left + 1,right + 1 };
			}
			else if (sum < target) {
				left++;
			}
			else {
				right--;
			}
		}
		return {};
	}
};
int main() {
	Solution sol;
	vector<int> numbers = { 1, 2, 3, 4 };
	int target = 3;
	vector<int> result = sol.twoSum(numbers, target);
	cout << "[" << result[0] << ", " << result[1] << "]";
	return 0;
}