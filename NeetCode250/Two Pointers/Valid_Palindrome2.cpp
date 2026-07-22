/*
Valid Palindrome II:

We are allowed to remove at most one character.

Use two pointers:
	left  -> beginning
	right -> end

While:
	left < right

If:
	s[left] == s[right]

move both pointers.

If:
	s[left] != s[right]

we have two choices:
	skip the left character
	OR
	skip the right character

Check both possibilities with a helper function.

If either remaining substring is a palindrome:
	return true

Otherwise:
	return false

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	bool validPalindrome(string s) {
		int left = 0;
		int right = s.length() - 1;
		while (left < right) {
			if (s[left] != s[right]) {
				bool skipLeft = isPalindrome(s, left + 1, right);
				bool skipRight = isPalindrome(s, left, right - 1);
				return skipLeft || skipRight;
			}
			left++;
			right--;
		}
		return true;
	}
};