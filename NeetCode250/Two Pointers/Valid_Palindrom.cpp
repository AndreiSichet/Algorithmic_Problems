/*
Valid Palindrome:

Use two pointers:
	left  -> beginning
	right -> end

Skip non-alphanumeric characters using:
	isalnum()

Compare characters ignoring case using:
	tolower()

If the characters are different:
	return false

After comparing:
	left++
	right--

If all characters match:
	return true

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<iostream>
#include <string>
using namesapce std;
class Solution {
public:
	bool isPalindrom(string s) {
		int left = 0;
		int right = s.length() - 1;
		while (left < right) {
			while (left < right && !isalnum(s[left])) {
				left++;
			}
			while (left < right && !isalnum(s[right])) {
				right--;
			}
			if (tolower(s[left]) != tolower(s[right])) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};
int main() {
	Solution sol;
	string s1 = "Was it a car or a cat I saw?";
	string s2 = "tab a cat";
	cout << "Example 1: "
		<< boolalpha
		<< sol.isPalindrome(s1)
		<< endl;
	cout << "Example 2: "
		<< sol.isPalindrome(s2)
		<< endl;
	return 0;
}
